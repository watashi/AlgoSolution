import Data.List
main = do getLine >>= print . fst . foldl f (0, 0)
f (a, b) '(' = (a, b + 1)
f (a, 0) ')' = (a, 0)
f (a, b) ')' = (a + 2, b - 1)
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--309030 	Feb 27, 2011 10:51:28 PM 	watashi 	26B - Regular Bracket Sequence 	Haskell 	Accepted 	380 ms 	49200 KB 
