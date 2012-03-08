
brev n = brev' 0 n
	where brev' m n
		| n == 0	= m
		| even n	= brev' (m * 2) (n `div` 2)
		| otherwise	= brev' (m * 2 + 1) (n `div` 2)

main =
	putStrLn $ show $ sum $ filter (\x -> reverse (show x) == show x && brev x == x) [1 .. 999999]
