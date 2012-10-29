getArray :: IO [Double]
getArray = fmap (map read . words) getLine

main = do
	[n, v] <- getArray
	a <- getArray
	b <- getArray
	putStr $ show $ min v $ sum a * minimum (zipWith (/) b a)

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--218458 	Dec 12, 2010 4:42:09 PM 	watashi 	A - Guilty – to the kitchen! 	Haskell 	Accepted 	30 ms 	1548 KB 
