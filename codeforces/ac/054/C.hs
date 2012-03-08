import Control.Monad

getA = fmap (map read . words) getLine

cnt n = let (m:t) = reverse $ takeWhile (<=n) $ iterate (*10) 1 in sum t + min m (n - m)

gao [] = [1.0]
gao ([l,r]:t) = zipWith (\i j -> p * i + (1 - p) * j) (0:a) (a++[0]) where
	u = r + 1
	p = fromInteger (cnt u - cnt l) / fromInteger (u - l)
	a = gao t

main = do
	[n] <- getA
	a <- replicateM (fromInteger n) getA
	[k] <- getA
	putStrLn $ show $ sum $ drop (fromInteger $ div (n * k + 99) 100) $ gao a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
248499 	Jan 13, 2011 6:41:38 PM 	watashi 	54C - First Digit Law 	Haskell 	Accepted 	140 ms 	12800 KB
-}
