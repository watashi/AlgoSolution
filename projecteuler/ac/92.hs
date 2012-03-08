import Data.Array
import Data.Char (digitToInt)
import Data.List (group)

stucks = listArray (1, 1000) $ [stuck i | i <- [1 .. 1000]]
stuck n
	| n == 1	= 1
	| n == 89	= 89
	| s <= 1000	= stucks ! s
	| otherwise	= stuck s
	where s = sum $ map ((^2) . digitToInt) $ show n

generate l d
	| l == 1	= [i | i <- [0 .. d]]
	| otherwise	= [i + j * 10 | i <- [0 .. d], j <- generate (l - 1) i]

factorial n = if n == 0 then 1 else n * factorial (n - 1)
permutaion n = product $ map (factorial . length) $ group $ take 7 $ reverse (show n) ++ repeat '0'

main = putStrLn $ show $ sum $ map ((factorial 7 `div`) . permutaion) $ filter ((==89) . stuck) $ tail $ generate 7 9

