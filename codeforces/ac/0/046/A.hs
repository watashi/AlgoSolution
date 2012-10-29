main = do getLine >>= putStrLn . unwords . (\n -> map (show . succ . (`mod` n)) $ scanl1 (+) [1 .. n - 1]) . read

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--213041 	Dec 10, 2010 1:24:30 PM 	watashi 	A - Ball Game 	Haskell 	Accepted 	30 ms 	1548 KB 
