main =
	putStrLn $ show $ sum $ map (read . (: "")) $ show $ foldl1 (*) [1 .. 100]
