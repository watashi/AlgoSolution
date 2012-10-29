main = do
	[n, m, a] <- fmap (map read . words) getLine
	putStrLn $ show $ ceiling (n / a) * ceiling (m / a)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
218669 	Dec 12, 2010 8:22:09 PM 	watashi 	A - Theater Square 	Haskell 	Accepted 	30 ms 	1552 KB
-}
