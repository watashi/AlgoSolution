main = do interact (show . (`div` 2) . product . map read . words)
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229276 	Dec 23, 2010 9:49:24 PM 	watashi 	A - Domino piling 	Haskell 	Accepted 	30 ms 	1548 KB
-}
