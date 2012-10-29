main = do
	getLine
	a <- fmap (zip [1 ..] . map read . words) getLine
	putStrLn $ unwords $ map show $ (\(_,(a,b))->[a,b]) $ minimum $ gao $ last a : a
gao :: [(Int, Int)] -> [(Int, (Int, Int))]
gao ((a,b):x@((c,d):_)) = (abs(b-d),(a,c)): gao x
gao _ = []

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230170 	Dec 27, 2010 10:56:17 AM 	watashi 	A - Reconnaissance 2 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
