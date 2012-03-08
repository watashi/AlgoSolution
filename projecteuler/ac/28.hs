main =
	putStrLn $ show $ sum $ 1 : concat [let m = (n + 1) ^ 2 in [m, m - n .. m - 3 * n] | n <- [2, 4 .. 1000]]
