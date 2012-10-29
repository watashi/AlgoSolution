import Char

getP = do
	[x, y] <- getLine
	return (ord x - 96, digitToInt y)
main = do
	(a, b) <- getP
	(c, d) <- getP
	putStrLn $ show $ sum [1 | i <- [1 .. 8], j <- [1 .. 8], i /= a, j /= b, i /= c || j /= d,
		and [z /= (a, b) && z /= (c, d) | x <- [-2 .. 2], y <- [-2 .. 2], abs x + abs y == 3, z <- [(i + x, j + y)]]]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235829 	Jan 1, 2011 9:29:05 PM 	watashi 	B - Chess 	Haskell 	Accepted 	30 ms 	1544 KB 
-}
