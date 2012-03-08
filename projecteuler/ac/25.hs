main =
	putStrLn $ show $ length $ takeWhile (< 10 ^ 999) fibs
	where
		fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
