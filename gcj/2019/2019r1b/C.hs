{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE RecordWildCards #-}

import Control.Monad
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Bits
import qualified Data.ByteString.Char8 as C
import Text.Printf
-- import Debug.Trace

-- -----------------------------------------------------------------------------
-- RMQ

data RMQ a = RMQ
  { rmqCmp :: a -> a -> Bool
  , rmqIdx :: Array Int (UArray Int Int)
  , rmqVal :: Array Int a
  }

logBase2 :: Int -> Int
logBase2 n = finiteBitSize n - 1 - countLeadingZeros n

rmqFromList :: (a -> a -> Bool) -> [a] -> RMQ a
rmqFromList rmqCmp a = RMQ{..}
  where
  n = length a
  cmp i j = if rmqCmp (rmqVal!i) (rmqVal!j) then i else j
  rmqVal = listArray (0, n-1) a
  rmqIdx = listArray (0, logBase2 n) $ go 1 $ indices rmqVal
    where
    go d idx
      | d > n = []
      | otherwise = listArray (0, n-d) idx: go (d + d) idx'
      where
      idx' = zipWith cmp idx $ drop d idx

-- [lo, hi)
rmqQuery :: RMQ a -> (Int, Int) -> (Int, a)
rmqQuery RMQ{..} (lo, hi) = if rmqCmp ai aj then (i, ai) else (j, aj)
  where
  k = logBase2 $ hi - lo
  i = rmqIdx!k!lo
  j = let mi = hi - 1 `unsafeShiftL` k in rmqIdx!k!mi
  ai = rmqVal!i
  aj = rmqVal!j

-- -----------------------------------------------------------------------------

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f = go
  where
  go lo hi
    | lo == hi = hi
    | f mi = go lo mi
    | otherwise = go (mi+1) hi
    where
    mi = (lo + hi) `quot` 2

main :: IO ()
main = do
  (re:_) <- readInts
  forM_ [1 :: Int .. re] $ \ri -> do
    (n:k:_) <- readInts
    a <- rmqFromList (>=) <$> readInts
    b <- rmqFromList (>=) <$> readInts
    let ans = sum $ map gao [0 .. n - 1] :: Int
        gao x =
          -- trace (printf "[%d] %d = [%d, %d) [%d, %d) [%d, %d)" x y al ar bl br cl cr) $
          (x - bl + 1) * (br - x) - (x - cl + 1) * (cr - x)
          where
          y = rmqVal a ! x
          z = rmqVal b ! x
          -- y
          al = bsearch (\i -> fst (rmqQuery a (i, x + 1)) == x) 0 x
          ar = bsearch (\i -> fst (rmqQuery a (x, i)) /= x) (x + 1) (n + 1) - 1
          -- y + k
          bl = bsearch (\i -> snd (rmqQuery b (i, x + 1)) <= y + k) al x
          br = bsearch (\i -> snd (rmqQuery b (x, i)) > y + k) (x + 1) (ar + 1) - 1
          -- y - k
          cl = bsearch (\i -> snd (rmqQuery b (i, x + 1)) < y - k) al x
          cr = bsearch (\i -> snd (rmqQuery b (x, i)) >= y - k) (x + 1) (ar + 1) - 1
    printf "Case #%d: %d\n" ri ans
  where
  readInts =
    map (\s -> let Just (i, _) = C.readInt s in i) . C.words <$> C.getLine
