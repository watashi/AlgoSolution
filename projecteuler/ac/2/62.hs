import Data.List

main = putStrLn $ show $ filter ((>4) . length) $ groupBy (\x y -> fst x == fst y) $ sort todo
	where todo = map (\x -> (sort $ show x, x)) $ [i ^ 3 | i <- [1 .. 9999]]
