import Data.List (delete)

generate [] _ c = [c]
generate _ [] c = [c]
generate a (b:bs) c = concat [generate (delete ai a) bs c' |
	ai <- a, let c' = c * 10 + ai, c' `mod` 1000 `mod` b == 0]

main = do
	putStrLn $ show $ sum $ generate [0 .. 9] [1, 1, 1, 2, 3, 5, 7, 11, 13, 17] 0
