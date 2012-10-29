import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Text.Printf

getArray :: Read a => IO [a]
getArray = fmap (map read . words) getLine

gao :: Int -> [[Double]] -> [Double]
gao n a = [dp!bit i | i <- [0 .. n - 1]] where
	p = listArray ((0, 0), (n - 1, n - 1)) $ concat a
	dp = listArray (0::Int, bit n - 1) $ [dp' i | i <- [0::Int .. bit n - 2]] ++ [1.0]
	dp' m = sum [dp!setBit m j * p!(i,j) | i <- x, j <- y] / c where
		(x, y) = partition (testBit m) [0 .. n - 1]
		c = let lx = length x in fromIntegral $ div (lx * succ lx) 2

main = do
	[n] <- getArray
	a <- replicateM n getArray
	putStrLn $ unwords $ map (printf "%.6f") $ gao n a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213026 	Dec 10, 2010 12:03:34 PM 	watashi 	E - Fish 	Haskell 	Accepted 	2840 ms 	21056 KB 
-}
