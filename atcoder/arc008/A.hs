main = do
    n <- fmap read getLine
    print $ minimum $ [x * 100 + y * 15 | i <- [0 .. 10], (x, y) <- [divMod (n + i) 10]]
