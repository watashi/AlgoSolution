import Data.Array

main = do
	[n] <- r
	a <- r
	b <- r
	putStrLn $ unlines $ let c = f n b ++ reverse (f n a) in show (length c): c where
		r = fmap (map read . words) getLine
		f n l = g [(j - 1, j) | i <- [1 .. n], j <- reverse [i + 1 .. n]] $ listArray (1, n) l
		g [] a = []
		g ((i, j): k) a = if a!i > a!j then (show i ++ " " ++ show j) : g k (a // [(i, a!j), (j, a!i)]) else g k a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241522 	Jan 7, 2011 9:26:38 PM 	watashi 	53D - Physical Education 	Haskell 	Accepted 	340 ms 	6680 KB 
-}
