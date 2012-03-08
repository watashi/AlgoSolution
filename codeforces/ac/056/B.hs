main = do interact (unwords . map show . gao . map read . tail . words)

gao a = if not (null b) && b == r c then [head c, last c] else [0, 0] where
	r = reverse
	f = r . dropWhile (uncurry (==))
	(b, c) = unzip $ f . f $ zip a [1 ..]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
267430 	Jan 29, 2011 8:44:08 PM 	watashi 	56B - Spoilt Permutation 	Haskell 	Accepted 	30 ms 	1600 KB
-}
