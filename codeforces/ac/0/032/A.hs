getA :: IO [Int]
getA = fmap (map read . words) getLine

main = do
	[n, d] <- getA
	a <- getA
	putStr $ show $ sum [1 | i <- a, j <- a, abs(i-j) <= d] - n

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230220 	Dec 27, 2010 5:46:58 PM 	watashi 	A - Reconnaissance 	Haskell 	Accepted 	50 ms 	2576 KB 
-}
