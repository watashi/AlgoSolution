import List
main = getLine >> fmap (map read . words) getLine >>= putStr . show . head . ([1 ..] \\)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219780 	Dec 16, 2010 10:43:21 PM 	watashi 	A - Next Test 	Haskell 	Accepted 	90 ms 	2576 KB
219779 	Dec 16, 2010 10:41:59 PM 	watashi 	A - Next Test 	Haskell 	Accepted 	110 ms 	2576 KB 
-}
