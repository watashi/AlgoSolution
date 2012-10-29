import Control.Monad

getA = fmap (map read . words) getLine

main = do
	[n] <- getA
	a <- replicateM n getA
	putStr $ last $ "NO":["YES" | [x,d] <- a, [y,t] <- a, x+d==y, y+t==x]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229776 	Dec 25, 2010 9:37:13 AM 	watashi 	A - Spit Problem 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
