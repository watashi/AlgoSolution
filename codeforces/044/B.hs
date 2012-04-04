main = do
	[n, a, b, c] <- fmap (map read . words) getLine
	print $ sum $ [1 | i <- [0 .. div a 2], j <- [0 .. c], k <- [n - i - j - j], 0 <= k, k <= b]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
404477 	Apr 21, 2011 2:06:35 PM 	watashi 	44B - Cola 	Haskell 	Accepted 	360 ms 	2000 KB 
-}
