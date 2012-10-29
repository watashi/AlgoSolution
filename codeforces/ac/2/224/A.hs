main = do
    a <- fmap (map read . words) getLine
    print $ let p = product a in sum $ map (\i -> (4*) $ floor $ sqrt $ p/i/i) a
