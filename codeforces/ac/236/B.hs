{-# OPTIONS -O2 -optc-O3 #-}
import Control.Arrow (second)
import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array (Array, listArray, (!))
import Data.Array.ST (STUArray, runSTUArray, newListArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, assocs)

idecomposition :: (Integral a, Integral b) => a -> a -> (a, b)
idecomposition n p
  | m /= 0    = (n, 0)
  | otherwise = second succ $ idecomposition d p
  where
    (d, m) = divMod n p

factor :: Int -> UArray Int Int
factor n = runSTUArray sieve
  where
	  sieve = do
		  a <- newListArray (1, n) [1 .. n] :: ST s (STUArray s Int Int)
		  forM_ [2 .. floor $ sqrt $ fromIntegral n] $ \i -> do
			  p <- readArray a i
			  when (p == i) $
				  forM_ [i, i + i .. n] $ \j -> writeArray a j i
		  return a

divisorNum :: Int -> Array Int Int
divisorNum n = a
  where
    a = listArray (1, n) $ map gao $ assocs $ factor n
    gao (1, 1) = 1
    gao (n, p) = let (q, r) = idecomposition n p in a!q * succ r

main = do
  [a, b, c] <- fmap (map read . words) getLine
  print $ (`mod` 2^30) $ sum [dn!(i*j*k) | i <- [1..a], j <- [1..b], k <- [1..c]]
  where
    dn = divisorNum 1000000
