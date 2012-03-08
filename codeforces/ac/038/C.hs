getA = fmap (map read . words) getLine
main = do
	[n, l] <- getA
	a <- getA
	putStrLn $ show $ maximum $ 0:[i * sum (map (`div` i) a) | i <- [l .. maximum a]]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235831 	Jan 1, 2011 9:35:52 PM 	watashi 	C - Blinds 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
