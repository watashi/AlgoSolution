import Control.Monad

main = do
    n <- fmap read getLine
    a <- replicateM n $ fmap (map read . words) getLine
    print $ sum [a!!i!!j | m <- [n - 1], i <- [0 .. m], j <- [0 .. m],
                    i == j || i + j == m || (odd n && (2 * i == m || 2 * j == m))]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643263 	Apr 29, 2012 8:32:58 AM 	watashi 	A2 - Good Matrix Elements (70 points) 	Haskell 	Accepted 	30 ms 	4100 KB
1643255 	Apr 29, 2012 8:26:15 AM 	watashi 	A1 - Good Matrix Elements (30 points) 	Haskell 	Accepted 	30 ms 	2100 KB
-}
