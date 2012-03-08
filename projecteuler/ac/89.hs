import IO

fromRoman s = uncurry (+) $ foldl (\(s, p) t -> (if p < t then s - p else s + p, t) ) (0, 0) $ map (\c ->
	case c of
		'M' -> 1000
		'D' -> 500
		'C' -> 100
		'L' -> 50
		'X' -> 10
		'V' -> 5
		'I' -> 1) $ s where

toRoman n = if n == 0 then "" else (\(a, b) -> b ++ toRoman (n - a)) $ head $ dropWhile ((>n) . fst) $
	[(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]

main = do
	handle <- openFile "89roman.txt" ReadMode
	input <- hGetContents handle
	print $ sum $ [length x - length (toRoman $ fromRoman $ x) | x <- lines input]

