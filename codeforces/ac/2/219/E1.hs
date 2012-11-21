{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad (replicateM)
import Data.Maybe (fromJust)
import qualified Data.Set as S
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

data Interval = Interval {
    begin   :: !Int,
    end     :: !Int,
    spacing :: !Int
  }
  deriving (Show, Eq)

interval n (l, r) = Interval l r m
  where
    m = if l == 0 || r == n then r - l else (r - l + 1) `div` 2

instance Ord Interval where
  compare a b =
    case compare (spacing a) (spacing b) of
      LT  -> GT
      EQ  -> compare (begin a) (begin b)
      GT  -> LT

data State = State {
    size :: Int,
    free :: S.Set Interval,
    l2r  :: M.IntMap Int,
    r2l  :: M.IntMap Int,
    pos  :: M.IntMap Int
  }
  deriving (Show)

top s = (l, r, center)
  where
    (Interval l r m) = S.findMin $ free s
    center
      | l == 0      = l
      | r == size s = r - 1
      | otherwise   = (l + r - 1) `div` 2

findByL l s = M.findWithDefault (-1) l $ l2r s

findByR r s = M.findWithDefault (-1) r $ r2l s

findById k = fromJust . M.lookup k . pos

delete (l, r) s@(State n sf ml mr _) = s {
    free = S.delete (interval n (l, r)) sf,
    l2r  = M.delete l ml,
    r2l  = M.delete r mr
  }

insert (l, r) s@(State n sf ml mr _)
  | l >= r    = s
  | otherwise = s {
      free = S.insert (interval n (l, r)) sf,
      l2r  = M.insert l r ml,
      r2l  = M.insert r l mr
    }

gao s [] = []

gao s (1:k:q) = p: gao s'{ pos = M.insert k p $ pos s' } q
  where
    (l, r, p) = top s
    s' = insert (l, p) $ insert (p + 1, r) $ delete (l, r) $ s

gao s (2:k:q) = gao s'{ pos = M.delete k $ pos s' } q
  where
    p = findById k s
    (l, sl) =
      case findByR p s of
        -1  -> (p, s)
        l   -> (l, delete (l, p) s)
    (r, sr) =
      case findByL (p + 1) sl of
        -1  -> (p + 1, sl)
        r   -> (r, delete (p + 1, r) sl)
    s' = insert (l, r) sr

main = do
  (n:m:q) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  putStr $ unlines $ map (show . succ) $ gao (empty n) q
  where
    empty n = State {
        size = n,
        free = S.singleton $ interval n (0, n),
        l2r  = M.singleton 0 n,
        r2l  = M.singleton n 0,
        pos  = M.empty
      }

{-
watashi-laptop:
  ./E1 < E.in > E.out  2.60s user 0.08s system 87% cpu 3.053 total
acm90:
  real	0m5.263s
  user	0m5.200s
  sys	0m0.064s
-}
