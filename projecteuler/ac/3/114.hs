dp = 1 : [dp' i | i <- [1 ..] ]
	where dp' i = dp !! (i - 1) + sum [dp !! (i - j) | j <- [4 .. i]]

main = do putStrLn $ show $ dp !! (50 + 1)
