main = do
	n <- fmap read getLine
	putStrLn $ if any (==n+n) [i * succ i | i <- [1 .. 99]] then "YES" else "NO"

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213187 	Dec 10, 2010 7:47:06 PM 	watashi 	A - Triangular numbers 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
