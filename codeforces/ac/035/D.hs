import IO
import List

main = do
	i <- openFile "input.txt" ReadMode
	o <- openFile "output.txt" WriteMode
	c <- hGetContents i
	hPutStr o $ show $ gao $ map read $ words c
	hClose o

gao (n:x:c) = length $ takeWhile (<=x) $ scanl1 (+) $ sort $ zipWith (*) [1 ..] $ reverse c

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230313 	Dec 28, 2010 6:58:06 AM 	watashi 	D - Animals 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
