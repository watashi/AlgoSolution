main = do
	[a, b, n] <- fmap (map read . words) getLine
	putStrLn $ last $ "No solution" : [show x | x <- [-1000 .. 1000], a * x ^ n == b]
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--313680 	Mar 1, 2011 10:24:27 PM 	watashi 	30A - Accounting 	Haskell 	Accepted 	30 ms 	2000 KB 

