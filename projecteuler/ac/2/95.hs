import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array.ST (STUArray, runSTUArray, newArray, newListArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, (!))
import Data.List (maximumBy)
import Data.Ord (comparing)

isqrt = floor . sqrt . fromIntegral

factor :: Int -> UArray Int Int
factor n = runSTUArray sieve
  where
	  sieve = do
		  a <- newListArray (0, n) [0 .. n] :: ST s (STUArray s Int Int)
		  forM_ [2 .. isqrt n] $ \i -> do
			  p <- readArray a i
			  when (p == i) $
				  forM_ [i, i + i .. n] $ \j -> writeArray a j i
		  return a

divisorSum :: Int -> UArray Int Int
divisorSum n = runSTUArray gao
  where
    factorList = factor n
    gao = do
      a <- newArray (0, n) 1 :: ST s (STUArray s Int Int)
      forM_ [2 .. n] $ \i -> do
        let q = takeWhile ((== 0) . (mod i)) $ scanl (*) 1 $ repeat $ factorList!i
        t <- readArray a $ div i $ last q
        writeArray a i $ t * sum q
      return a

limit = 1000000

divisorSumList = divisorSum limit

chain n = chain' n []
  where
    chain' x a
      | y > limit = []
      | y < n     = []
      | y == n    = reverse $ x:a
      | elem y a  = []
      | otherwise = chain' y $ x:a
      where
        y = divisorSumList!x - x

main = do
  print $ maximumBy (comparing length) $ [chain i | i <- [1 .. limit]]
