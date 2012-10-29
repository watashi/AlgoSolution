import Control.Monad
import Data.List

getA = fmap (map read . words) getLine

main = do
	[w,h,n] <- getA
	a <- replicateM n getA
	putStr $ unwords $ map show $ sort $ gao [0,0,w,h] a

gao [x1,y1,x2,y2] [] = [(x2 - x1) * (y2 - y1)]
gao [x1,y1,x2,y2] a = gao r p ++ gao s q where
	c@[x3,y3,x4,y4] = head $ filter (\[i,j,k,l] -> (i==x1 && k==x2) || (j==y1 && l==y2)) a
	(r@[x5,y5,x6,y6],s) = if x3==x4 then ([x1,y1,x3,y2],[x3,y1,x2,y2]) else ([x1,y1,x2,y3],[x1,y3,x2,y2])
	(p,q) = partition (\[i,j,k,l] -> x5<=i && y5<=j && k<=x6 && l<=y6) $ delete c a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230205 	Dec 27, 2010 4:29:10 PM 	watashi 	D - Chocolate 	Haskell 	Accepted 	50 ms 	1548 KB 
-}
