import Data.Char

main = putStrLn $ show $ product $ map (digitToInt . (digits !!)) [10 ^ i | i <- [0 .. 6]]
	where digits = concat [show i | i <- [0 ..]]
