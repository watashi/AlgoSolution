main =
	putStrLn $ show $ count 0 [1]

count n c
	| n > 100	= 0
	| otherwise = length (filter (>1000000) c) + count (n + 1) (zipWith (+) (0 : c) (c ++ [0]))
