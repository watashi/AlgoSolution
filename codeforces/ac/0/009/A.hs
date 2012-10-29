main = do
	line <- getLine
	putStrLn $ head $ [show (div n g) ++ "/" ++ show (div d g) |
		n <- [(7-) $ maximum $ map read $ words line], d <- [6], g <- [gcd n d]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
209186 	Dec 6, 2010 6:00:25 PM 	watashi 	A - Die Roll 	Haskell 	Accepted 	30 ms 	1548 KB
-}
