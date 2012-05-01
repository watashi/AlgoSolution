main = do
    getContents >>= putStrLn . unlines . map gao . tail . lines where
        gao s = show $ succ $ (2*) $ div k $ lcm (gcd a b) (gcd c d) where
            [a, b, c, d, k] = map read $ words s
