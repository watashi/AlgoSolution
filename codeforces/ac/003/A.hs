gao (s@[a,b]) (t@[c,d]) = if s == t then [] else (i++j) : gao [x,y] t where
	(i, x) = f a c "R" "L"
	(j, y) = f b d "U" "D"
	f u v s p = if u < v then (s, succ u) else if u > v then (p, pred u) else ([], u)

main = do
	s <- getLine
	t <- getLine
	putStrLn $ show $ length $ gao s t
	putStrLn $ unlines $ gao s t

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--255693 	Jan 20, 2011 7:47:43 PM 	watashi 	3A - Shortest path of the king 	Haskell 	Accepted 	30 ms 	1500 KB 
