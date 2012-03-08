main = do fmap (map read . words) getLine >>= putStrLn . gao where
	gao [a, b, c, d] = let g = gcd c d; x = div c g; y = div d g; e = min (div a x) (div b y) in show (e * x) ++ " " ++ show (e * y)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
212867 	Dec 9, 2010 10:20:37 PM 	watashi 	C - Monitor 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
