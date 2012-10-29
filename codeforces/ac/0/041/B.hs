getArray = fmap (map read . words) getLine

main = do
	[n, b] <- getArray
	a <- getArray
	putStrLn $ show $ maximum $ zipWith (\x y -> b + div b y * (x - y)) a $ scanl1 min a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213418 	Dec 11, 2010 6:43:10 PM 	watashi 	B - Martian Dollar 	Haskell 	Accepted 	50 ms 	1548 KB 
-}
