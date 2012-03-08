main = do
	contents <- getContents
	putStrLn $ let a = lines contents in if reverse (map reverse a) == a then "YES" else "NO"

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--209271 	Dec 6, 2010 8:39:36 PM 	watashi 	A - Super Agent 	Haskell 	Accepted 	50 ms 	1540 KB 
