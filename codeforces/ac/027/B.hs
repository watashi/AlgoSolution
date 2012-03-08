import Control.Monad
import Data.Array

main = do
	[n] <- getA
	a <- replicateM (n * (n - 1) `div` 2 - 1) getA
	putStr $ unwords $ map show $ gao n a where
		getA = fmap (map read . words) getLine

gao n a = if w!x > w!y then [x, y] else [y, x] where
	[w, l] = [accumArray (+) 0 (1, n) $ zip (map f a) $ repeat 1 | f <- [head, last]]
	[x, y] = filter (\i -> w!i + l!i < n - 1) [1 .. n]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229650 	Dec 24, 2010 10:15:18 PM 	watashi 	B - Tournament 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
