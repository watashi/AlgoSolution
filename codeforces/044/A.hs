import Data.List (sort, group)
main = do interact (show . length . group . sort . tail . lines)
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
404403 	Apr 21, 2011 12:52:01 PM 	watashi 	44A - Indian Summer 	Haskell 	Accepted 	30 ms 	2000 KB 
-}
