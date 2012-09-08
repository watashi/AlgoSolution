main = do
    c <- fmap head getLine
    s <- getLine
    putStrLn $ filter (/= c) s
