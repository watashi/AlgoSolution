import Data.List (sort)

main = do
	line <- getLine
	putStrLn $ gao $ sort $ map read $ words line

gao a =
	if a !! 0 + a !! 1 > a !! 2 || a !! 0 + a !! 2 > a !! 3 || a !! 1 + a !! 2 > a !! 3 then
		"TRIANGLE"
	else if a !! 0 + a !! 1 == a !! 2 || a !! 0 + a !! 2 == a !! 3 || a !! 1 + a !! 2 == a !! 3 then
		"SEGMENT"
	else
		"IMPOSSIBLE"

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
201333 	Nov 30, 2010 6:55:20 PM 	watashi 	A - Triangle 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
