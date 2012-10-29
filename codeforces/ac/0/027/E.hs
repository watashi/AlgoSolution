main = do getLine >>= putStr . show . gao (10^20) [2, 3, 5, 7, 11, 13, 17, 19, 23] 1 . read

gao m    [] _ _ = m
gao m     _ s 1 = min m s
gao m (p:q) s n = if s > m then m else foldl (\i j -> gao i q (s*p^(j-1)) (div n j)) m d where
	d = filter ((==0) . (mod n)) [2 .. n]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229772 	Dec 25, 2010 9:22:36 AM 	watashi 	E - Number With The Given Amount Of Divisors 	Haskell 	Accepted 	10 ms 	1548 KB 
-}
