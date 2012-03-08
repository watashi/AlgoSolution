-- when n is odd, r = 2na % a^2
-- when n is even, r = 2 % a^2

main = do putStrLn $ show $ sum $ map (\a -> 2 * div (a - 1) 2 * a) [3 .. 1000]
