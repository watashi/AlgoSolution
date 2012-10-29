main = do
	[n, m, s] <- fmap (map read . words) getLine
	putStrLn $ show $ gao n s * gao m s where
		gao a b = let (c, d) = divMod a b in if d == 0 then a else succ c * d

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230225 	Dec 27, 2010 6:05:25 PM 	watashi 	C - Flea 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
