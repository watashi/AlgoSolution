main = do
    (n:a) <- fmap (map read . words) getContents
    let ans = concatMap (replicate n) a
    putStr $ unlines $ map show ans