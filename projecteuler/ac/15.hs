main =
	putStrLn $ show $ foldl (\y x -> y * (n + 1 - x) `div` x) 1 [1 .. m]
	where
		n = 20 + 20
		m = 20
