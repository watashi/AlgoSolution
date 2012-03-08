import Data.IntMap

main =
	putStrLn $ show $ maximum $ Prelude.map (\(a, b) -> (b, a)) $
		toList $ fromListWith (+) $
		Prelude.map (\(a, b, c) -> (a + b + c, 1)) $
		Prelude.filter (\(a, b, c) -> a + b + c <= 1000 && c > 0) triple

square = fromList [(x * x, x) | x <- [1 .. 1000]]

triple = [(a, b, findWithDefault 0 (a * a + b * b) square) | a <- [1 .. 500], b <- [a .. 1000 - a]]
