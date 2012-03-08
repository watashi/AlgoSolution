main = do
	line <- getLine
	putStrLn (let x = read line in if x > 2 && even x then "YES" else "NO")

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
200402 	Nov 29, 2010 9:07:46 PM 	watashi 	A - Watermelon 	Haskell 	Accepted 	30 ms 	1548 KB
-}
