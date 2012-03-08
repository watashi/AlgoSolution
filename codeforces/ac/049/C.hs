-- IDEA:?

isp n = and $ map ((/=0) . (mod n)) $ takeWhile ((<=n) . (^2)) [2 ..]

gao 0 = []
gao n = gao (p - 1) ++ [n + p - i | i <- [p .. n]] where
	p = until (isp . (+n)) succ 1

main = do getLine >>= putStr . unwords . map show . gao . read

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229544 	Dec 24, 2010 6:55:21 PM 	watashi 	C - Disposition 	Haskell 	Accepted 	80 ms 	1564 KB 
-}
