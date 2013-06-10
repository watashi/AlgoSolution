main =
	putStrLn $ show $ sum $ map (\x -> pow x x) [1 .. 1000]

pow a b
	| b == 0 = 1
	| even b = c ^ 2 `mod` m
	| otherwise = c ^ 2 * a `mod` m
	where
		c = pow a (b `div` 2)
		m = 10 ^ 10
