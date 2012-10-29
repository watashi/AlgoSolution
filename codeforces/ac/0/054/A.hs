main = do
	[n, k] <- getA
	_:c <- getA
	putStrLn $ show $ pred $ sum $ zipWith (\i j -> ceiling $ (j - i) / k) (0:c) $ c ++ [n + 1] where
	getA = fmap (map read . words) getLine

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
248406 	Jan 13, 2011 4:23:38 PM 	watashi 	54A - Presents 	Haskell 	Accepted 	30 ms 	1600 KB 
-}
