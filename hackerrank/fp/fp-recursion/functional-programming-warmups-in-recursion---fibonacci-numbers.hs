--Contributed by Ron Watkins
module Main where


fib n = fst $ iterate (\(i, j) -> (j, i + j)) (0, 1) !! (n - 1)


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
    input <- getLine
    print . fib . (read :: String -> Int) $ input
