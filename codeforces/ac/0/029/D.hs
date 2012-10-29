import Control.Monad
import Data.Array
import Data.Maybe
import Data.List

getA = fmap (map read . words) getLine

main = do
	[n] <- getA
	e <- replicateM (n - 1) getA
	o <- getA
	putStr $ gao n o $ accumArray (flip (:)) [] (1, n) $ concat [[(a, b), (b, a)] | [a, b] <- e]

gao n o e = if fst x <= snd x then unwords (map show y) else "-1" where
	(x, y) = tr 1 0
	tr v p =
		if null w then
			((q, q), [v])
		else if fst $ foldl (\(a,b) (c,d) -> (a && b < c && c <= d, d)) (True, -1) r then
			((fst $ head r, snd $ last r), concat [v:i | i <- s] ++ [v])
		else
			((n, -1), [])
		where
			q = fromJust $ elemIndex v o
			w = filter (/=p) (e!v)
			(r, s) = unzip $ sortBy (\i j -> compare (fst i) (fst j)) $ map (flip tr v) w

{-
-- a && b < c && ***c <= d*** WA25
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229788 	Dec 25, 2010 10:56:33 AM 	watashi 	D - Ant on the Tree 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
