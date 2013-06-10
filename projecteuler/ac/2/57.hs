import Data.Ratio

sqrt2 = map (\x -> 1 / x + 1) $ scanl1 (\x y -> 1 / x + y) $ take 1000 $ repeat 2

main = putStrLn $ show $ length $ filter (\x -> ls (numerator x) > ls (denominator x)) sqrt2
	where ls = length . show

