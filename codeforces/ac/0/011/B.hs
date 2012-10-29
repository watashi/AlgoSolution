main = do interact (show . gao . read)
gao n = head [i | i <- [0 ..], j <- [i * (i + 1) `div` 2], odd j == odd n, j >= abs n]
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--275643 	Feb 5, 2011 5:13:24 PM 	watashi 	11B - Jumping Jack 	Haskell 	Accepted 	30 ms 	1600 KB 
