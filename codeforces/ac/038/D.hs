import Control.Monad
import Data.List

_in l r x = l <= x && x <= r
getA = fmap (map read . words) getLine
std [a,b,c,d] = map fromIntegral [min a c, min b d, max a c, max b d]
gao l = and $ zipWith3 (\i j [a,b,c,d] -> _in a c i && _in b d j) (f x z) (f y z) (head l:l) where
	(x,y,z) = unzip3 $ map (\[a,b,c,d] -> ((a+c)/2, (b+d)/2, (c-a)^3)) l
	f p m = zipWith (/) (scanr1 (+) $ zipWith (*) p m) (scanr1 (+) m)
main = do
	[n] <- getA
	a <- replicateM n getA
	putStrLn $ show $ maximum $ map length $ takeWhile gao $ inits $ map std a

-- takeWhile *not* filter
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235837 	Jan 1, 2011 10:04:31 PM 	watashi 	D - Vasya the Architect 	Haskell 	Accepted 	30 ms 	1552 KB 
-}
