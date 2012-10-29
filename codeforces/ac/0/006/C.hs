main = do
	dummy <- getLine
	line <- getLine
	putStrLn (let t = map read $ words line; a = gao t; b = length t - a in show a ++ " " ++ show b)

gao a = gao' 0 (length a) where
	b = 0: scanl1 (+) a
	s = last b
	gao' l r
		| l < r		= let m = (l + r) `div` 2 in if b!!m <= s - b!!(m+1) then gao' (m + 1) r else gao' l m
		| otherwise	= r

{--
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
201378 	Nov 30, 2010 7:47:05 PM 	watashi 	C - Alice, Bob and Chocolate 	Haskell 	Accepted 	950 ms 	21044 KB 
--}
