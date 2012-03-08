-- p_{c=a+b}-p_a=p_b+3ab=p_d (p_a > p_d)

-- pentagonal
p = [n * (3 * n - 1) `div` 2 | n <- [0 .. ] ]

-- isPentagonal p = (==p) $ head $ dropWhile (<p) pentagonal
isPentagonal m = let n = ceiling $ sqrt $ fromIntegral m * 2 / 3 in n * (3 * n - 1) `div` 2 == m

main = do putStrLn $ show $ concat $ map check [1 .. ]
	where check d =
		map (\(a, _, d) -> p !! a - p !! d) $
		filter (\(a, _, d) -> isPentagonal $ p !! a - p !! d) $
		map (\b -> (div (p !! d - p !! b) (3 * b), b, d)) $
		filter (\b -> mod (p !! d - p !! b) (3 * b) == 0) $
		takeWhile (\b -> p !! d - p !! b > 3 * d * b) [1 .. d - 1]
