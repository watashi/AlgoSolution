main = putStrLn $ show $ mod (28433 * pow 2 7830457 + 1) m
	where
		m = 10000000000 :: Integer
		pow a b
			| b == 0 = 1
			| even b = mod (c * c) m
			| otherwise = mod (a * c * c) m
			where c = pow a (div b 2)

