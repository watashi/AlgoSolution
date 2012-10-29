main = do
	dummy <- getLine
	todo <- getContents
	putStrLn $ if gao (lines todo) then "YES" else "NO"

gao [] = True
gao (a:b) = gao b && a == take (length a) (repeat (head a)) && (b == [] || a /= head b)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
212847 	Dec 9, 2010 9:48:23 PM 	watashi 	A - Flag 	Haskell 	Accepted 	30 ms 	1540 KB 
-}
