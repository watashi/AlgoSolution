main =
	putStrLn $ show $ maximum $ map (\x -> (fst $ pellEQU $ x, x)) $ filter (\x -> isqrt x ^ 2 /= x) [2 .. 1000]

isqrt n =
	last $ takeWhile((<= n) . (^ 2)) [1 ..]

cFracSqrt d = cFracSqrt' d 0 1
	where cFracSqrt' d c q
		| a == 2 * t = [a]
		| otherwise = a : cFracSqrt' d c' q'
		where
			t = isqrt d
			a = (t + c) `div` q
			c' = a * q - c
			q' = (d - c' ^ 2) `div` q

toFrac [] = (1, 0)
toFrac (x:xs) = (n, d)
	where
		(n', d') = toFrac xs
		n = x * n' + d'
		d = n'

pellEQU d
	| odd $ length a = toFrac $ init a
	| otherwise = toFrac $ a ++ (init . tail $ a)
	where a = cFracSqrt d

