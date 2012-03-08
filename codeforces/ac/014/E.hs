import Data.Array

dp = array ((2,0,0), (20,20,3)) [((i,j,k), f i j k) | i <- [2 .. 20], j <- [0 .. 20], k <- [0 .. 3]] where
	f 2 0 k = k
	f 2 _ _ = 0
	f i j k = sum [dp!(i-1,j',k') | j' <- [max 0 (j - 1) .. j], k' <- if odd j then [k + 1 .. 3] else [0 .. k - 1]]

main = fmap (map read . words) getLine >>= putStrLn . show . gao where
	gao [n, t] = sum [dp!(n,t+t-1,k) | k <- [0 .. 3]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
212599 	Dec 8, 2010 9:20:24 PM 	watashi 	E - Camels 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
