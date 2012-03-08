import List

eval x "+" y = x + y
eval x "*" y = x * y

gao a [] = head a
gao a (o:b) = let n = length a in minimum [gao (eval x o y: (a \\ [x, y])) b | x <- a, y <- delete x a]

main = do
	a <- fmap (map read . words) getLine
	b <- fmap words getLine
	putStrLn $ show $ gao (take 4 a) (take 3 b)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
251414 	Jan 14, 2011 1:42:04 PM 	watashi 	B - Smallest number 	Haskell 	Accepted 	30 ms 	1552 KB 
-}
