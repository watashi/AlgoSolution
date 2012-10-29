main = do getLine >> getLine >>= putStrLn . show . gao . map read . words
gao a = sum $ zipWith (*) (0:c) $ init d where
	s = sum a
	b = scanl1 (+) a
	c = scanl1 (+) $ map (\i -> if 3 * i == s then 1 else 0) $ b
	d = map (\i -> if 3 * i == 2 * s then 1 else 0) $ b
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--283370 	Feb 12, 2011 6:23:35 PM 	watashi 	21C - Stripe 2 	Haskell 	Accepted 	1130 ms 	17000 KB
