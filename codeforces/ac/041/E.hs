main = do
	a <- fmap (gao . read) getLine
	putStrLn $ show $ length a
	mapM_ (putStrLn . unwords . map show) a

gao n = [[i, j] | m <- [div n 2], i <- [1 .. m], j <- [m + 1 .. n]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213452 	Dec 11, 2010 8:42:01 PM 	watashi 	E - 3-cycles 	Haskell 	Accepted 	60 ms 	1548 KB 
-}
