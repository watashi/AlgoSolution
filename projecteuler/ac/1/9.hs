main = putStrLn $ show $ filter (>0) $ map gao triple
	where
		triple = [(a, b, 1000 - a - b) | a <- [1 .. 500], b <- [1 .. 500]]
		gao (a, b, c)
			| a < b && c > 0 && a * a + b * b == c * c = a * b * c
			| otherwise = 0

