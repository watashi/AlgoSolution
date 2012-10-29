main = interact $ (\[a, b] -> if a == reverse b then "YES" else "NO") . lines

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--213247 	Dec 11, 2010 1:05:44 AM 	watashi 	A - Translation 	Haskell 	Accepted 	30 ms 	1540 KB
