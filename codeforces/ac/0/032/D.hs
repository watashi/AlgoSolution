import Control.Arrow
import Control.Monad
import Data.Array

main = do
	[n, m, k] <- fmap (map read . words) getLine
	a <- replicateM n getLine
	putStr $ head $ (++["-1"]) $ drop (k - 1) $ gao n m $ listArray ((1,1),(n,m)) $ concat a

gao n m a = [unlines $ map (\(i, j) -> show i ++ " " ++ show j) z |
	r <- [1 .. min n m - 1],
	s <- [[id *** id, flip (-) r *** id, (+r) *** id, id *** flip (-) r, id *** (+r)]],
	x <- [r + 1 .. n - r],
	y <- [r + 1 .. m - r],
	a!(x, y) == '*',
	z <- [map (\k -> k (x, y)) s],
	and [a!(i, j) == '*' | (i, j) <- z]]

{-
List => TLE34; Array => AC
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230232 	Dec 27, 2010 6:54:31 PM 	watashi 	D - Constellation 	Haskell 	Accepted 	1700 ms 	4628 KB
-}
