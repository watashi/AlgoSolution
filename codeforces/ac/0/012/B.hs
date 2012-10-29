import Data.List ((\\), sort)

main = do
	alice <- getLine
	bob <- getLine
	putStrLn $ if gao alice == bob then "OK" else "WRONG_ANSWER"

gao "0" = "0"
gao a = let a0 = minimum (filter (/= '0') a); a1 = a \\ [a0] in a0 : sort a1

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--209274 	Dec 6, 2010 8:47:03 PM 	watashi 	B - Correct Solution? 	Haskell 	Accepted 	30 ms 	1540 KB 
