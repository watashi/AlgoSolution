import Data.Array

dp n = if n == 0 then 1 : take 9 (repeat 0) else scanl1 (+) $ dp $ pred n 

main = do let n = 100 in putStrLn $ show $ sum $ -(9 * n + 1) : dp n ++ [sum $ tail $ dp i | i <- [1 .. n]]

