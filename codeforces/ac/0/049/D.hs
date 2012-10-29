main = do
	n <- getLine
	s <- getLine
	putStr $ show $ minimum [length $ filter id $ zipWith (==) s $ f $ concat $ repeat "01" | f <- [id, tail]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229553 	Dec 24, 2010 7:18:56 PM 	watashi 	D - Game 	Haskell 	Accepted 	30 ms 	1540 KB
-}
