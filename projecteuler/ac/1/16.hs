main =
	putStrLn $ show $ sum $ map (read . (: "")) $ show $ 2 ^ 1000 
