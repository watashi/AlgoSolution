main = do getLine >>= putStr . unwords . map show . (\n -> n:[1..n-1]) . read
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229547 	Dec 24, 2010 6:58:48 PM 	watashi 	C - Disposition 	Haskell 	Accepted 	80 ms 	1564 KB 
-}
