main = do interact $ unwords . map show . takeWhile (>0) . iterate f . read
f 1 = 0
f n = div n $ head $ [i | i <- [2 ..], mod n i == 0]
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--271587 	Jan 31, 2011 9:24:17 PM 	watashi 	58B - Coins 	Haskell 	Accepted 	130 ms 	31300 KB 
