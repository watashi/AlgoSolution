import Control.Monad

getA = fmap (map read . words) getLine
hypot x y = sqrt . fromIntegral $ x ^ 2 + y ^ 2

main = do
	[n] <- getA
	[k, e] <- getA
	[x, y] <- getA
	p <- replicateM n getA
	putStr $ show $ gao n k (1 - fromIntegral e/1000) $ map (\[i, j] -> hypot (i - x) (j - y)) p

gao n k e d = gao' 0 3000 where
	gao' l r = if r - l < 0.1 ^ 8 then m else if q > e then gao' l m else gao' m r where
		m = (l + r) / 2
		p = map (\i -> if i <= m then 1 else exp $ 1 - (i / m) ^ 2) d
		q = sum $ drop k $ go p

go [] = [1]
go (p:ps) = let q = go ps in zipWith (\i j -> p * i + (1 - p) * j) (0:q) (q ++ [0])

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229417 	Dec 24, 2010 11:50:40 AM 	watashi 	D - Bombing 	Haskell 	Accepted 	60 ms 	1552 KB
-}
