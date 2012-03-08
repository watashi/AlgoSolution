import Data.Char (digitToInt)
main = putStrLn $ show $ sum $ filter (\x -> (sum $ map ((^5) . digitToInt) $ show x) == x) $ [2 .. 2^20]
