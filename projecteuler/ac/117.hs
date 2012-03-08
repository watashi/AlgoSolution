dp = 1 : [dp' i | i <- [1 ..] ]
	where dp' i = sum [if i - j < 0 then 0 else dp !! (i - j) | j <- [1 .. 4]]

main = do putStrLn $ show $ dp !! 50
