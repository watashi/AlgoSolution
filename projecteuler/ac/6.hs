main =
	let n = 100
	in putStrLn $ show $ sum [1 .. n] ^ 2 - sum [x ^ 2 | x <- [1 .. n]]
