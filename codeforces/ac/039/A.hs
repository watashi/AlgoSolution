main = do interact (gao . map read . words)
gao (x:y:_) = if r^2 == d || odd r == (signum x == signum y) then "black" else "white" where
	d = x^2 + y^2
	r = head $ dropWhile ((<d) . (^2)) [0 ..]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235507 	Dec 30, 2010 9:24:41 PM 	watashi 	A - Find Color 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
