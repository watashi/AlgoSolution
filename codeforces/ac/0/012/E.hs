main = do
	line <- getLine
	putStrLn $ unlines $ [unwords [show $ gao n i j | j <- [0 .. n - 1]] | n <- [read line], i <- [0 .. n - 1]]
	where gao n i j
		| i > j			= gao n j i
		| i == j		= 0
		| i + j < n		= i + j
		| j == pred n	= if i + i < n then i + i else i + i + 1 - n
		| otherwise		= i + j + 1 - n

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--211801 	Dec 7, 2010 9:18:23 PM 	watashi 	E - Start of the session 	Haskell 	Accepted 	340 ms 	1564 KB 
