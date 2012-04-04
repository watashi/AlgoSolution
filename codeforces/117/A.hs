import Control.Monad

main = do
    [n, m] <- fmap (map read . words) getLine
    a <- replicateM n $ fmap (map read . words) getLine
    putStrLn $ unlines $ map (show . gao m) a

gao m [s, f, t] = if s == f then t else b where
    a = gao' s t
    b = gao' f a
    gao' s t = u * r + w where
        r = 2 * (m - 1)
        (u, v) = divMod t r
        w
            | s >= v + 1                = s - 1
            | s <= m - (v - (m - 1))    = (m - 1) + (m - s)
            | otherwise                 = r + s - 1

-- Time limit exceeded on test 19
