main = do
    (n:a) <- fmap (map read . words) getContents :: IO [Int]
    putStr $ unlines $ map show $ filter (<n) a