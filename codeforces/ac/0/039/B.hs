main = do interact (show . gao . map read . words)
gao (n:m:x:_) = f(2*x-2) - f(2*x) where
	f y = if n > y && m > y then div ((n-y)*(m-y)+1) 2 else 0
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235509 	Dec 30, 2010 9:34:16 PM 	watashi 	B - Repaintings 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
