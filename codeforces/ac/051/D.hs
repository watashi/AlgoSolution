main = do getLine; getLine >>= putStr . show . gao . map (fromInteger . read) . words
gao [0, 0] = 0
gao [0, _] = 1
gao x = if length x < 3 then 0 else minimum $ 2:[f i (if j == 0 then 0 else j / i) x | (i, j) <- [(b, c), (a, c), (a, b)], j == 0 || i /= 0] where
	(a:b:c:_) = x
	f _ _ [] = 0
	f a b (h:t) = if a == h then f (a*b) b t else f a b t + 1
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235266 	Dec 30, 2010 8:00:07 AM 	watashi 	D - Geometrical problem 	Haskell 	Accepted 	610 ms 	13864 KB 
-}
