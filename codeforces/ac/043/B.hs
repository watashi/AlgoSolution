import Data.List ((\\))

main = do
	a <- getLine
	b <- getLine
	putStrLn $ if filter (/= ' ') b \\ a == [] then "YES" else "NO"

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
208971 	Dec 6, 2010 11:57:15 AM 	watashi 	B - Letter 	Haskell 	Accepted 	30 ms 	1540 KB 
-}

