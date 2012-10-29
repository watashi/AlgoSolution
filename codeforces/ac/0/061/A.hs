main = do
	a <- getLine
	b <- getLine
	putStrLn $ zipWith (\i j -> if i == j then '0' else '1') a b
