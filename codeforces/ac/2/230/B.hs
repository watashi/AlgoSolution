{-# OPTIONS -O2 -optc-O3 #-}
import Control.Arrow ((***))
import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array.ST (STUArray, runSTUArray, newArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, (!), assocs)

isqrt :: (Integral a, Integral b) => a -> b
isqrt = floor . sqrt . fromIntegral

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

primeTab :: UArray Int Bool
primeTab = sieveToN 1000000

isPrime :: Integral a => a -> Bool
isPrime n = n >= 2 && primeTab!fromIntegral n

main = do
  getLine
  getLine >>= putStrLn . unlines . map (gao . read) . words
  where
    gao n = let m = isqrt n in if m * m == n && isPrime m then "YES" else "NO"
