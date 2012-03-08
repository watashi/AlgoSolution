main =
	putStrLn $ show $ maximum $ map gao ab
	where
		gao = sum . map (read . (: "")) . show . uncurry (^)
		ab = [(a, b) | a <- l, b <- l]
		l = takeWhile (< 100) [1 ..]
