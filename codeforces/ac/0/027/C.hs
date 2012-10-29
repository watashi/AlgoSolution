import Data.Array
import List

getA = fmap (map read . words) getLine

main = do
	[n] <- getA
	x <- getA
	putStr $ let r = gao n x in unlines [show (length r), unwords (map show r)]

gao n x = if null e then [] else head e where
	a = listArray (1, n) x
	b = map head $ groupBy (\i j -> a!i == a!j) [1 .. n]
	c = length b
	d = listArray (1, c) b
	e = filter (\[i, j, k] -> (a!i < a!j) /= (a!j < a!k)) [[d!(i-1), d!i, d!(i+1)] | i <- [2 .. c - 1]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229657 	Dec 24, 2010 10:35:47 PM 	watashi 	C - Unordered Subsequence 	Haskell 	Accepted 	1190 ms 	27220 KB 
-}
