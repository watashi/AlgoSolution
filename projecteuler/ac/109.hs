a = [0, 25, 50] ++ concat [[i, 2 * i, 3 * i] | i <- [1 .. 20]]
b = 50 : [2 * i | i <- [1 .. 20]]
c = [a !! i + a !! j + k | i <- [0 .. length a - 1], j <- [i .. length a - 1], k <- b]
main = do putStrLn $ show $ length $ filter (< 100) c
