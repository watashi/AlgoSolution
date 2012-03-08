{-# OPTIONS -O2 -optc-O -XBangPatterns #-}
module Primes (primesToN) where

import Control.Monad
import Control.Monad.ST
import Data.Array.IArray
import Data.Array.MArray
import Data.Array.ST
import Data.Array.Unboxed

isqrt = floor . sqrt . fromIntegral

primeToNA :: Int -> UArray Int Bool
primeToNA n = runSTUArray sieve where
	sieve = do
		a <- newArray (2, n) True :: ST s (STUArray s Int Bool)
		let sr = isqrt n
		forM_ [4, 6 .. n] $ \j -> writeArray a j False
		forM_ [3, 5 .. sr] $ \i -> do
			si <- readArray a i
			when si $
				forM_ [i * i, i * (i + 2) .. n] $ \j -> writeArray a j False
		return a

primesToN :: Int -> [Int]
primesToN n = [i | (i, e) <- assocs . primeToNA $ n, e]
