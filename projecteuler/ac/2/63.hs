main = putStrLn $ show $ sum $ takeWhile (>0) $ map ((10-) . gao) $ [1 ..]
	where gao n = head $ dropWhile (\x -> x ^ n < 10 ^ (n - 1)) [1 ..]
