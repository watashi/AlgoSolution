m = 50
dp = 1 : [dp' i | i <- [1 ..] ]
	where dp' i = dp !! (i - 1) + sum [dp !! (i - j) | j <- [m + 1 .. i]]

main = do putStrLn $ show $ (length $ takeWhile (<=1000000) dp) - 1
