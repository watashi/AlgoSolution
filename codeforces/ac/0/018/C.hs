import Data.Int

main = do interact $ show . gao . map read . tail . words where
	gao :: [Int32] -> Int
	gao a = let (s:b) = scanr1 (+) a in length $ filter (\i -> i + i == s) b

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--213079 	Dec 10, 2010 2:47:52 PM 	watashi 	C - Stripe 	Haskell 	Accepted 	1720 ms 	15916 KB 
