{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE RecordWildCards #-}
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Bits
import qualified Data.ByteString.Char8 as C
import Data.List

main :: IO ()
main = do
  (n:k:a) <- map readInt . C.words <$> C.getContents
  let s = listArray (0, n) $ scanl (+) 0 a :: UArray Int Int
      maxRmq = rmqFromList (>=) $ elems s
      minRmq = rmqFromList (<=) $ elems s
      next from = (to, s!to - s!from)
        where
        to = max (from + 1) $ fst $ rmqQuery maxRmq (from, end)
        end = go (from+1) (n+1)
        go lo hi
          | lo == hi = hi
          | snd (rmqQuery minRmq (lo, mi+1)) < s!from = go lo mi
          | otherwise = go (mi+1) hi
          where
          mi = lo + (hi - lo) `quot` 2
      ans = take k $ sortBy (flip compare) $ filter (>0) $ map snd $
        takeUntil ((==n) . fst) $ iterate (next . fst) (0, -1)
  mapM_ print ans
  where
  readInt s = let Just (i, _) = C.readInt s in i
  takeUntil _ [] = []
  takeUntil p (h:t)
    | p h = [h]
    | otherwise = h: takeUntil p t

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

rmqQuery :: RMQ a -> (Int, Int) -> (Int, a)
rmqQuery RMQ{..} (lo, hi) = if rmqCmp ai aj then (i, ai) else (j, aj)
  where
  k = logBase2 $ hi - lo
  i = rmqIdx!k!lo
  j = let mi = hi - 1 `unsafeShiftL` k in rmqIdx!k!mi
  ai = rmqVal!i
  aj = rmqVal!j
