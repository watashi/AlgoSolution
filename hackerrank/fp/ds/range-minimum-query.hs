{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE MagicHash #-}
{-# LANGUAGE RecordWildCards #-}
{-# LANGUAGE UnboxedTuples #-}

import Control.Applicative
import Control.Monad
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Bits
import qualified Data.ByteString.Char8 as C
import GHC.Prim
import GHC.Types

data RMQ a = RMQ
  { rmqCmp :: a -> a -> Bool
  , rmqIdx :: Array Int (UArray Int Int)
  , rmqVal :: Array Int a
  }

-- https://downloads.haskell.org/~ghc/7.8.3/docs/html/libraries/
logBase2 :: Int -> Int
logBase2 (I# x) = I# ret
  where
  (# _, ret #) = go 1# (go 2# (go 4# (go 8# (go 16# (# x, 0# #)))))

  go :: Int# -> (# Int#, Int# #) -> (# Int#, Int# #)
  go k (# n, m #) = case uncheckedIShiftRA# n k of
    0# -> (# n, m #)
    n' -> (# n', m +# k #)

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

rmqQuery :: RMQ a -> (Int, Int) -> (Int, a)
rmqQuery RMQ{..} (lo, hi) = if rmqCmp ai aj then (i, ai) else (j, aj)
  where
  k = logBase2 $ hi - lo
  i = rmqIdx!k!lo
  j = let mi = hi - 1 `unsafeShiftL` k in rmqIdx!k!mi
  ai = rmqVal!i
  aj = rmqVal!j
  
main :: IO ()
main = do
  (n:m:inputs) <- map readInt . C.words <$> C.getContents
  let (a, q) = splitAt n inputs
      rmq = rmqFromList (<=) a
  forM_ (takeWhile (not . null) $ iterate (drop 2) q) $ \(l:r:_) ->
    print $ snd $ rmqQuery rmq (l, r + 1)
  where
  readInt s = let Just (i, _) = C.readInt s in i