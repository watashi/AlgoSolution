import IO

gao :: [Int] -> Int
gao [a] = a
gao (a:b:c:d) = gao $ (if a == b then c else if a == c then b else a):d

main = do
	hi <- openFile "input.txt" ReadMode
	ho <- openFile "output.txt" WriteMode
	hGetContents hi >>= hPutStr ho . show . gao . map read . words
	hClose ho

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230241 	Dec 27, 2010 7:24:15 PM 	watashi 	A - Shell Game 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
