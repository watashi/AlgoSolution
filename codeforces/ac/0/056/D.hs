import Data.Array

main = do
	a <- getLine
	b <- getLine
	putStrLn $ unlines $ map unwords $ let s = gao a b in [show $ length s] : reverse s

gao a b = dump n m where
	n = length a
	m = length b
	s = listArray (0,n) ('^':a)
	t = listArray (0,m) ('^':b)
	dp = listArray ((0,0),(n,m)) [f i j | i <- [0 .. n], j <- [0 .. m]]
	f 0 0 = (0, '$')
	f i j =
		if s!i == t!j then
			(fst $ dp!(i-1,j-1), 'O')
		else
			minimum [(succ $ fst $ dp!(x,y), z) | (x,y,z) <- [
				(i - 1, j, 'D'),
				(i, j - 1, 'I'),
				(i - 1, j - 1, 'R')], x >= 0, y >= 0]
	dump i j = let x = i - 1; y = j - 1 in case snd $ dp!(i,j) of
		'D' -> ["DELETE", show $ j + 1] : dump x j
		'I' -> ["INSERT", show j, [t!j]] : dump i y
		'R' -> ["REPLACE", show j, [t!j]] : dump x y
		'O' -> dump x y
		'$' -> []

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--267790 	Jan 30, 2011 2:44:23 PM 	watashi 	56D - Changing a String 	Haskell 	Accepted 	810 ms 	77500 KB 

