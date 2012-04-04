main = do
    [a, b, n] <- fmap (map read . words) getLine
    print $ (`mod` 2) $ length $ takeWhile (>=0) $ scanl (\n m -> n - gcd n m) n $ concat $ repeat [a, b]
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--1156011 	Feb 7, 2012 6:59:48 PM 	watashi 	119A - Epic Game 	Haskell 	Accepted 	30 ms 	2000 KB
