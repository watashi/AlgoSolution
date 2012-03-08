import Control.Monad
import Data.Array
import IO

gao n l = elems a where
	a = listArray (1, n) [maximum $ 0:[a!j + s (b!j) (b!i) | j <- [1 .. i - 1]] | i <- [1 .. n]]
	b = listArray (1, n) l
	s [x,a,b] [y,c,d] = min x $ maximum $ 0:[f, g, h] where
		i = (b - a) / x
		j = (d - c) / y
		f = (c - a) / i
		g = if d <= b then (d - a) / i - y else 0
		h = if b <= d then x - (b - c) / j else 0

main = do
	i <- openFile "input.txt" ReadMode
	o <- openFile "output.txt" WriteMode
	n <- fmap read $ hGetLine i
	l <- replicateM n $ fmap (map read . words) $ hGetLine i
	hPutStrLn o $ show $ maximum $ zipWith (+) (map head l) (gao n l)
	hClose i
	hClose o

{-
TLE36: listArray
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
236009 	Jan 2, 2011 7:54:48 PM 	watashi 	C - Bowls 	Haskell 	Accepted 	1340 ms 	3616 KB
-}
