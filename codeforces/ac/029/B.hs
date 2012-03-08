main = do getLine >>= putStr . show . gao . map read . words
gao [l,d,v,g,r] = f (l+y) / f v where
	f = fromIntegral
	x = mod d ((g+r)*v)
	y = if x<g*v then 0 else (g+r)*v-x
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229777 	Dec 25, 2010 9:46:24 AM 	watashi 	B - Traffic Lights 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
