gao [a, b]
	| a > b		= gao [b, a]
	| a == 1	= a
	| a == b	= a
	| otherwise	= gao [a, b - (b - 2) `div` (a - 1) * (a - 1)]
main = do getLine >>= print . gao . map read . words
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
395995 	Apr 19, 2011 12:19:11 AM 	watashi 	74C - Chessboard Billiard 	Haskell 	Accepted 	30 ms 	2000 KB 
-}
