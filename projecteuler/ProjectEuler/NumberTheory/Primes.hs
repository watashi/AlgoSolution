{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
module ProjectEuler.NumberTheory.Primes (
  primesTo,
  primesFromTo
  ) where

import ProjectEuler.NumberTheory.Powers (isqrt)

import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array.ST (STUArray, runSTUArray, newArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, assocs)
import Data.Int (Int64)

-- | The 'primesTo' function returns the list of primes up to the given limit.
primesTo :: Int -> [Int]
primesTo n = map fst $ filter snd $ assocs $ sieveTo n

sieveTo :: Int -> UArray Int Bool
sieveTo n = runSTUArray sieve
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

-- | The 'primesFromTo' function returns the list of primes in the given range.
primesFromTo :: Int64 -> Int64 -> [Int64]
primesFromTo m n
  | m < 2     = primesFromTo 2 n
  | m <= n    = map fst $ filter snd $ assocs $ sieveFromTo m n
  | otherwise = []

sieveFromTo :: Int64 -> Int64 -> UArray Int64 Bool
sieveFromTo m n = runSTUArray sieve
  where
    d = isqrt n
    sieve = do
      a <- newArray (m, n) True :: ST s (STUArray s Int64 Bool)
      forM_ (map fromIntegral $ primesTo $ fromIntegral d) $ \i -> do
        let s = max i $ (m + i - 1) `quot` i
        forM_ [i * s, i * (s + 1) .. n] $ \j ->
          writeArray a j False
      return a

