import Control.Monad
import Data.Array
import List

main = do
	[n, m] <- getA
	e <- replicateM m getA
	putStr $ show' $ gao m $ listArray (1, m) $ map sort e where
		getA = fmap (map read . words) getLine
		show' (Just a) = elems a
		show' _ = "Impossible"

inter x@[a,b] y@[c,d] = if a > c then inter y x else a < c && c < b && b < d

gao n e = foldl f (Just $ listArray (1, n) $ repeat '?') [1 .. n] where
	f z@(Just a) i = if a!i == '?' then g 'o' z i else z
	f _ _ = Nothing
	g c z@(Just a) i = if a!i == c then z else if a!i /= '?' then Nothing else r where
		b = filter (\j -> inter (e!i) (e!j)) [1 .. n]
		d = if c == 'o' then 'i' else 'o'
		r = foldl (g d) (Just $ a // [(i, c)]) b
	g _ _ _ = Nothing

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229769 	Dec 25, 2010 8:51:14 AM 	watashi 	D - Ring Road 2 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
