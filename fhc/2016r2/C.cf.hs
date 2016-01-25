{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE MagicHash #-}
{-# LANGUAGE RecordWildCards #-}
{-# LANGUAGE UnboxedTuples #-}

import Control.Applicative
import Control.Monad
import Control.Monad.Trans.State.Strict
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Bits
import Data.List
import Data.Maybe
import Data.Int (Int64)
import qualified Data.ByteString.Char8 as C
import GHC.Prim
import GHC.Types

-- -----------------------------------------------------------------------------
-- MInt

newtype MInt = MInt Int64
  deriving (Enum)

z :: Int64
z = 1000000007

instance Show MInt where
  show (MInt a) = show a

instance Num MInt where
  (+) (MInt a) (MInt b) = let c = a + b in MInt $ if c >= z then c - z else c
  (-) (MInt a) (MInt b) = let c = a - b in MInt $ if c >= 0 then c else c + z
  (*) (MInt a) (MInt b) = MInt $ a * b `rem` z
  abs = id
  negate (MInt a) = if a == 0 then 0 else MInt $ z - a
  signum (MInt a) = if a == 0 then 0 else 1
  fromInteger a = MInt $ fromInteger $ a `mod` toInteger z

-- -----------------------------------------------------------------------------
-- RMQ

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

-- -----------------------------------------------------------------------------

-- \sum{i<=j}{\(\sum{i<=k<=j}{a_k}\)^2}
gao :: (Enum a, Num a) => [a] -> a
gao d = sum $ zipWith (*) d sumAll
  where
  sumAll = scanl1 (+) $ zipWith (-) sumRight sumLeft
  sumLeft = sumOf d
  sumRight = reverse . sumOf . reverse $ d
  sumOf a = [i * j - k | (i, j, k) <- zip3 [1..] s x]
    where
    s = scanl (+) 0 a
    x = scanl1 (+) s

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Int, [(Int, Int)]) -> MInt
solve (n, p0) = go (0, n) `execState` 0
  where
  p = sort p0
  x = listArray (0, n-1) $ map fst p :: UArray Int Int
  rmq = rmqFromList (>=) $ map snd p

  go :: (Int, Int) -> State MInt ()
  go cur@(lo, hi) = when (lo < hi) $ do
    modify (+ gao ds)
    forM_ (zip ((lo-1): is) $ is ++ [hi]) $ \(i, j) ->
      go (i+1, j)
    where
    (i0, h) = rmqQuery rmq cur
    ds = map fromIntegral $ zipWith (-) (tail xs) xs :: [MInt]
    xs = map (x!) is :: [Int]
    is = reverse $ next i0 `execState` []
    next i = do
      modify (i:)
      let (i', h') = rmqQuery rmq (i+1, hi)
      when (i < hi - 1 && h == h') $ next i'

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    n <- readInt <$> C.getLine
    p <- replicateM n $ do
      (x:y:_) <- map readInt . C.words <$> C.getLine
      return (x, y)
    let ans = solve (n, p)
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
