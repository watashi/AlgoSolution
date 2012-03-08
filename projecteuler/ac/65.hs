main =
	putStrLn $ show $ digitsum $ fst $ toFrac e
	where e = 2 : [case i `mod` 3 of {0 -> i `div` 3 * 2; otherwise -> 1} | i <- [2 .. 100]]

digitsum x
	| x == 0 = 0
	| otherwise = r + digitsum q
	where (q, r) = quotRem x 10

isqrt n =
	last $ takeWhile((<= n) . (^ 2)) [1 ..]

toFrac [] = (1, 0)
toFrac (x:xs) = (n, d)
	where
		(n', d') = toFrac xs
		n = x * n' + d'
		d = n'

