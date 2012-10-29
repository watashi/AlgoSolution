main = do getLine >>= putStrLn . unwords . map show . gao . read where
	gao n = [if odd i then 1 + div i 2 else n - div i 2 | i <- [0 .. n - 1]]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241442 	Jan 7, 2011 8:40:47 PM 	watashi 	53C - Little Frog 	Haskell 	Accepted 	30 ms 	1564 KB 
-}
