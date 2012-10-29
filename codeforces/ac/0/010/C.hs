main = do interact (show . gao . read)
gao n = sum d - sum e where
	c = [div (n + 9 - i) 9 | i <- 9:[1 .. 8]]
	d = [(c!!i) * (c!!j) * (c!!k) | i <- [0 .. 8], j <- [0 .. 8], k <- [mod (i * j) 9]]
	e = [div n i | i <- [1 .. n]]
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--275549 	Feb 5, 2011 2:40:17 PM 	watashi 	10C - Digital Root 	Haskell 	Accepted 	80 ms 	1600 KB 
