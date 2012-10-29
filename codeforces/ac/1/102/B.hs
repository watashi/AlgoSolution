import Data.Char

main = do getLine >>= print . length . takeWhile ((>1) . length) . iterate (show . sum . map digitToInt)

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--602675 	Aug 11, 2011 4:54:59 PM 	watashi 	102B - Sum of Digits 	Haskell 	Accepted 	50 ms 	4100 KB 

