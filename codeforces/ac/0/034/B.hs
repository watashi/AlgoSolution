import List
getA = fmap (map read . words) getLine
main = do
	[n, m] <- getA
	a <- getA
	putStr $ show $ negate $ sum $ take m $ sort $ filter (<0) a
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230171 	Dec 27, 2010 11:01:35 AM 	watashi 	B - Sale 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
