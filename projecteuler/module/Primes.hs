{-# OPTIONS -O2 -optc-O3 #-}
module Primes (
  primesToN,
  primesFromMToN,
  primeDivision,
  isPrime,
  nextPrime
  ) where

import Control.Arrow ((***))
import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array.ST (STUArray, runSTUArray, newArray, newListArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, (!), assocs)
import Data.Int (Int64)

--
isqrt :: (Integral a, Integral b) => a -> b
isqrt = floor . sqrt . fromIntegral

threshold :: Integral a => a
threshold = fromIntegral threshold'
threshold' :: Int
threshold' = 1000000

primeList :: Integral a => [a]
primeList = map fromIntegral $ primeList'
primeList' :: [Int]
primeList' = primesToN threshold

-- primesToN
sieveToN :: Int -> UArray Int Bool
sieveToN n = runSTUArray sieve
  where
    sieve = do
      a <- newArray (2, n) True :: ST s (STUArray s Int Bool)
      forM_ [4, 6 .. n] $ \j ->
        writeArray a j False
      forM_ [3, 5 .. isqrt n] $ \i -> do
        ai <- readArray a i
        when ai $
          forM_ [i * i, i * (i + 2) .. n] $ \j ->
            writeArray a j False
      return a

primesToN :: (Integral a, Integral b) => a -> [b]
primesToN n = map (fromIntegral . fst) $ filter snd $ assocs $ sieveToN n'
  where
    n' = fromIntegral n

-- primesFromMToN
sieveFromMToN :: Int64 -> Int64 -> UArray Int64 Bool
sieveFromMToN m n = runSTUArray sieve
  where
    n' = isqrt n
    primes = if n' > threshold then primesToN n' else takeWhile (<=n') primeList
    sieve = do
      a <- newArray (m, n) True :: ST s (STUArray s Int64 Bool)
      forM_ primes $ \i -> do
        let s = max i $ div (m + i - 1) i
        when (i * s <= n) $
          forM_ [i * s, i * (s + 1) .. n] $ \j ->
            writeArray a j False
      return a

primesFromMToN :: (Integral a, Integral b) => a -> a -> [b]
primesFromMToN m n = map (fromIntegral . fst) $ filter snd $ assocs $ sieveFromMToN m' n'
  where
    m' = fromIntegral m
    n' = fromIntegral n

-- primeDivision
primeDivision :: Integral a => a -> [(a, Int)]
primeDivision n = f n $ primeList ++ [threshold + 1, threshold + 3 ..]
  where
    f n q
      | n == 1        = []
      | mod n p /= 0  = [(n, 1)]
      | otherwise     = (p, r): f m t
      where
        (p: t) = dropWhile (\i -> i * i <= n && mod n i /= 0) q
        (m, r) = until (\(i, j) -> mod i p /= 0) ((`div` p) *** succ) (n, 0)

-- isPrime
isPrime :: Integral a => a -> Bool
isPrime n = case primeDivision n of
                 [(_, 1)] -> True
                 _        -> False

-- nextPrime
nextPrime :: Integral a => a -> a
nextPrime = until isPrime succ
