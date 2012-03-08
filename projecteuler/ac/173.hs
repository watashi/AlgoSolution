main = do putStrLn $ show $ sum $ takeWhile (>0) [((floor $ sqrt $ fromInteger $ x * x + 1000000) - x) `div` 2 | x <- [1 ..]]
