import Data.List (sort, group)
import Text.Printf (printf)

main = do
	dummy <- getLine
	line <- getLine
	contents <- getContents
	uncurry (printf "%d %d\n") $ gao (map read $ words line) (lines contents)

gao x y = (gao' x1 yy, gao' x2 yy) where
	x1 = sort x
	x2 = reverse x1
	yy = reverse $ sort $ map length $ group $ sort y
	gao' x' y' = sum $ zipWith (*) x' y'

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--209552 	Dec 7, 2010 11:21:12 AM 	watashi 	C - Fruits 	Haskell 	Accepted 	30 ms 	1560 KB 
