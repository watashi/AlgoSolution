main = do
    [n, m] <- fmap (map read . words) getLine
    print $ last $ takeWhile (>=0) $ map (m-) $ scanl (+) 0 $ concat $ repeat [1 .. n]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
508502 	Jun 23, 2011 10:45:08 AM 	watashi 	92A - Chips 	Haskell 	Accepted 	30 ms 	2000 KB
-}
