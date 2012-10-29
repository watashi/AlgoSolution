main = do interact (show . gao . map read . words)
gao (n:x:m:y:_) = (if n + m < d then 1 else 2) + div (f n m + f m n) 2 where
	d = abs (x - y)
	f a b = let g c = if 1 <= c && c <= b then 1 else 0 in
		sum [2 * e - v |
			(l, r) <- map (\i -> (abs $ d - i, d + i)) [1 .. a],
			v <- [g l + g r + 2 * max 0 (min b (r-1) - max 1 (l+1) + 1)],
			e <- [max 1 v]]
{-
WA7: 1 0 1 100 // if n + m < d then 1 else 2
V + F - E = c
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235701 	Dec 31, 2010 9:49:59 PM 	watashi 	C - Berland Square 	Haskell 	Accepted 	60 ms 	1548 KB
-}
