main = do getLine >>= print . gao . map read . words
gao [n, k] = f 0 (n * k) where
    g m = sum $ takeWhile (>0) $ iterate (`div` k) m
    f l r
        | l == r    = r
        | otherwise = let m = div (l + r) 2 in if g m < n then f (m + 1) r else f l m
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1408590 	Mar 25, 2012 4:34:05 PM 	watashi 	165B - Burning Midnight Oil 	Haskell 	Accepted 	30 ms 	2100 KB
-}
