import Data.List(sort)

main = putStrLn $ maximum $ filter ((=="123456789") . sort) $ map generate [1 .. 10000]

generate n = generate' "" 1
	where generate' s i
		| length s < 9	= generate' (s ++ show (i * n)) (i + 1)
		| otherwise		= s

