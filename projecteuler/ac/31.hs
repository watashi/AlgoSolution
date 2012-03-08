coins = [1, 2, 5, 10, 20, 50, 100, 200]

count a s
	| s == 0	= 1
	| a == []	= 0
	| otherwise	= sum $ map (count (tail a)) [s, s - head a .. 0]

main = putStrLn $ show $ count (reverse coins) 200
