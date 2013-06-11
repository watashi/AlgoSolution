import Data.List
main = do interact (unwords . map show . gao . map read . tail . words)
gao a
	| null p && s < 2	= [if z then 0 else maximum n]
	| otherwise			= p ++ if even s then n else init (sort n)
	where
		z = any (==0) a
		(p, n) = partition (>0) $ filter (/=0) a
		s = length n
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
413375 	Apr 28, 2011 2:20:54 AM 	watashi 	45I - TCMCF+++ 	Haskell 	Accepted 	30 ms 	2000 KB 
-}
