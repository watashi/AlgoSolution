import Data.Array

n = 4

dp = a where
	a = array ((2, 0, 0, 0, 0), (20, 10, 10, 1, 3)) [((i', j', k', l', m'), dp' i' j' k' l' m') |
		i' <- [2 .. 20], j' <- [0 .. 10], k' <- [0 .. 10], l' <- [0 .. 1], m' <- [0 .. 3]]
	dp' 2 0 0 0 m	= m
	dp' 2 0 0 1 m	= n - 1 - m
	dp' 2 _ _ _ _	= 0
	dp' i j k l m
		| l == 0	= sum [dp!(i',j,k,0,m') + (if k' < 0 then 0 else dp!(i',j,k',1,m')) | m' <- [0 .. m - 1]]
		| l == 1	= sum [(if j' < 0 then 0 else dp!(i',j',k,0,m')) + dp!(i',j,k,1,m') | m' <- [m + 1 .. n - 1]]
		where i' = pred i; j' = pred j; k' = pred k

main = do
	line <- getLine
	putStrLn $ show $ gao $ map read $ words line
	where gao a = let n = head a; t = last a in sum [dp!(n,t,t-1,l,m) | l <- [0 .. 1], m <- [0 .. 3]]

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--212494 	Dec 8, 2010 5:14:44 PM 	watashi 	E - Camels 	Haskell 	Accepted 	50 ms 	3604 KB

