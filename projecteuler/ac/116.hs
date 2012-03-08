dp j = a
	where
		a = 1 : [dp' i | i <- [1 ..] ]
		dp' i = a !! (i - 1) + if i - j < 0 then 0 else a !! (i - j)
dps = [] : [dp j | j <- [1 ..] ]

main = do putStrLn $ show $ sum [dps !! j !! 50 | j <- [2 .. 4]] - 3
