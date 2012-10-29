import Data.List (sort, group)

main = do interact $ (++ "\n") . head . select . (++ [[]]) . group . sort . tail . lines
	where select l = if length (l!!0) > length (l!!1) then l!!0 else l!!1

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
208961 	Dec 6, 2010 11:47:42 AM 	watashi 	A - Football 	Haskell 	Accepted 	30 ms 	1540 KB 
-}
