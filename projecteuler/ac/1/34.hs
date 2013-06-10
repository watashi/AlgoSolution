import Data.Char (digitToInt)

factorial n = factorials !! n
	where factorials = scanl1 (*) (1 : [1 .. 9])

main = putStrLn $ show $ sum $ filter curious [3 .. factorial 9]
	where curious x = (sum $ map (factorial . digitToInt) $ show x) == x
