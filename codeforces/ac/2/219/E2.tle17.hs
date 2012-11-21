{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad (replicateM)
import Data.Maybe (fromJust)
import Data.Ord (comparing)
import Debug.Trace (trace)
import qualified Data.Set as S
import qualified Data.Sequence as A
import qualified Data.ByteString.Char8 as C

data Interval = Interval {
    begin   :: Int,
    end     :: Int,
    spacing :: Int
  }
  deriving (Show, Eq)

interval n (l, r) = Interval l r m
  where
    m = if l == 0 || r == n then r - l else (r - l + 1) `div` 2

center n (Interval l r _)
  | l == 0    = l
  | r == n    = r - 1
  | otherwise = (l + r - 1) `div` 2

instance Ord Interval where
  compare = comparing (\i -> (negate $ spacing i, begin i))

data State = State {
    size :: Int,
    free :: S.Set Interval,
    l2r  :: A.Seq Int,
    r2l  :: A.Seq Int,
    pos  :: A.Seq Int
  }
  deriving (Show)

top s = ((begin interval, end interval), center (size s) interval)
  where
    interval = S.findMin $ free s

findByL l s = let r = A.index (l2r s) l in if r == -1 then Nothing else Just (l, r)

findByR r s = let l = A.index (r2l s) r in if l == -1 then Nothing else Just (l, r)

findById k s = A.index (pos s) k

delete (l, r) s@(State n sf ml mr _) = s {
    free = S.delete (interval n (l, r)) sf,
    l2r  = A.update l (-1) ml,
    r2l  = A.update r (-1) mr
  }

insert (l, r) s@(State n sf ml mr _)
  | l >= r    = s
  | otherwise = s {
      free = S.insert (interval n (l, r)) sf,
      l2r  = A.update l r ml,
      r2l  = A.update r l mr
    }

gao s [] = []

gao s (1:k:q) = p: gao s'{ pos = A.update k p $ pos s' } q
  where
    ((l, r), p) = top s
    s' = insert (l, p) $ insert (p + 1, r) $ delete (l, r) $ s

gao s (2:k:q) = gao s'{ pos = A.update k (-1) $ pos s' } q
  where
    p = findById k s
    (l, sl) =
      case findByR p s of
        Just (l, r) -> (l, delete (l, r) s)
        Nothing     -> (p, s)
    (r, sr) =
      case findByL (p + 1) sl of
        Just (l, r) -> (r, delete (l, r) sl)
        Nothing     -> (p + 1, sl)
    s' = insert (l, r) sr

main = do
  (n:m:q) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  putStr $ unlines $ map (show . succ) $ gao (insert (0, n) $ empty n) q
  where
    empty n = State {
        size = n,
        free = S.empty,
        l2r  = A.fromList $ replicate (n + 1) $ -1,
        r2l  = A.fromList $ replicate (n + 1) $ -1,
        pos  = A.fromList $ replicate (10^6 + 1) $ -1
      }

-- ./E2 < E.in > E.out  7.76s user 0.17s system 94% cpu 8.427 total

