{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad
-- import Control.Monad.ST
-- import Data.Array.ST
import Data.Array.IO
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.Set as S
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

{-
data State s = State {
    size :: Int,
    free :: S.Set Interval,
    l2r  :: STUArray s Int Int,
    r2l  :: STUArray s Int Int,
    pos  :: STUArray s Int Int
  }
-}
data State = State {
    size :: Int,
    free :: S.Set Interval,
    l2r  :: IOUArray Int Int,
    r2l  :: IOUArray Int Int,
    pos  :: IOUArray Int Int
  }

top s = return (l, r, center)
  where
    (Interval l r m) = S.findMin $ free s
    center
      | l == 0      = l
      | r == size s = r - 1
      | otherwise   = (l + r - 1) `div` 2

empty n = do
  l2r <- newArray (0, n) $ -1 -- :: ST s (STUArray s Int Int)
  r2l <- newArray (0, n) $ -1
  pos <- newArray (0, 10^6) $ -1
  return $ State n S.empty l2r r2l pos

insert (l, r) s = do
  if l >= r
    then return s
    else do
      writeArray (l2r s) l r
      writeArray (r2l s) r l
      return s{free = S.insert (interval (size s) (l, r)) $ free s}

delete (l, r) s = do
  writeArray (l2r s) l $ -1
  writeArray (r2l s) r $ -1
  return s{free = S.delete (interval (size s) (l, r)) $ free s}

gao s [] =
  return []

gao s (1:k:q) = do
  (l, r, p) <- top s
  s <- delete (l, r) s
  s <- insert (l, p) s
  s <- insert (p + 1, r) s
  writeArray (pos s) k p
  ps <- gao s q
  return $ p: ps

gao s (2:k:q) = do
  p <- readArray (pos s) k
  l' <- readArray (r2l s) p
  (l, s) <-
    if l' == -1
      then return (p, s)
      else do
        s <- delete (l', p) s
        return (l', s)
  r' <- readArray (l2r s) (p + 1)
  (r, s) <-
    if r' == -1
      then return (p + 1, s)
      else do
        s <- delete (p + 1, r') s
        return (r', s)
  s <- insert (l, r) s
  writeArray (pos s) k $ -1
  gao s q

solve n q = do
  s <- empty n
  s <- insert (0, n) s
  gao s q

main = do
  (n:m:q) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  ans <- solve n q
  putStr $ unlines $ map (show . succ) $ ans {- runST $ solve n q -}

{-
IOUArray:
  watashi-laptop:
    ./E3 < E.in > E.out  1.09s user 0.04s system 92% cpu 1.226 total
  acm90:
    real	0m6.047s
    user	0m5.976s
    sys	0m0.072s
STUArray:
  watashi-laptop:
    ./E3 < E.in > E.out  1.79s user 0.08s system 90% cpu 2.057 total
  acm90:
    real	0m7.916s
    user	0m7.868s
    sys	0m0.040s
getLine -> getContents: 0.85s
-}

