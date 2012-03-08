main = do
	n:b:a <- fmap (map read . words) getContents
	putStrLn $ show $ maximum $ zipWith (\x y -> b + div b y * (x - y)) a $ scanl1 min a

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--213420 	Dec 11, 2010 6:45:56 PM 	watashi 	B - Martian Dollar 	Haskell 	Accepted 	60 ms 	1548 KB 

