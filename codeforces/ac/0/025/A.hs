import Data.List
main = do
	dummy <- getLine
	l <- fmap (map read . words) getLine
	putStrLn $ show $ snd $ head $ (\(a,b) -> if length a == 1 then a else b) $ partition (odd . fst) $ zip l [1 ..]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219409 	Dec 15, 2010 4:19:20 PM 	watashi 	A - IQ test 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
