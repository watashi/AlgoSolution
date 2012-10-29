main = do
	n <- fmap read getLine
	a <- fmap (map read . words) getLine
	putStr $ unwords $ map show $ last $ [-1]:[[i, j, k] | i <- [1 .. n], j <- [1 .. n], k <- [1 .. n], i /= j, i /= k, j /= k, a!!(i-1) == a!!(j-1) + a!!(k-1)]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230185 	Dec 27, 2010 12:15:53 PM 	watashi 	A - Worms Evolution 	Haskell 	Accepted 	250 ms 	1548 KB 
-}
