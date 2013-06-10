import Data.Ratio
import Data.List (delete, group, sort)

-- permutation
permutation [] = [[]]
permutation xs = [x:ys | x <- xs, ys <- permutation (delete x xs)]

-- unique
unique = map head . group

eval xs
	| length xs == 1	= xs
	| otherwise			= unique $ sort $ concat [ o l r |
		o <- [
			(\a b -> if a > b then [] else [a + b]),
			(\a b -> [a - b]),
			(\a b -> if a > b then [] else [a * b]),
			(\a b -> if b == 0 then [] else [a / b])],
		p <- [1 .. length xs - 1],
		l <- eval $ take p xs,
		r <- eval $ drop p xs]

result = map numerator . filter ((==1) . denominator) . unique . sort . concat . map eval . permutation

size = length . takeWhile (uncurry (==)) . zip [1 ..] . dropWhile (<=0) . result

main = putStrLn $ show $ filter ((>40) . snd) $ map (\x -> (map numerator x, size x)) todo
	where todo = [[a, b, c, d] | a <- [0 .. 9], b <- [a + 1 .. 9], c <- [b + 1 .. 9], d <- [c + 1 .. 9]]

