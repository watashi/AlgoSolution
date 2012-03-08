import Control.Monad
import Data.Array
import Data.Int
import Data.List

main = do
	[n, m] <- fmap (map read . words) getLine
	a <- replicateM n getLine
	putStrLn $ (show::Int64->String) $ gao n m a

gao n m a = sum [row!i * col!j | i <- [1 .. n], j <- [1 .. m], mat!(i,j) == '*'] where
	cnt l = listArray (1, length l) $ map (fromIntegral . pred . length . filter (=='*')) $ l
	row = cnt a
	col = cnt $ transpose a
	mat = listArray ((1,1), (n,m)) $ concat a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241350 	Jan 7, 2011 7:30:38 PM 	watashi 	52B - Right Triangles 	Haskell 	Accepted 	560 ms 	54904 KB 
-}
