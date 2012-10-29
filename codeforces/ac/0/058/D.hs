import Control.Monad
import Data.Array
import Data.List

main = do
	n <- fmap read getLine
	a <- replicateM n getLine
	b <- getLine
	putStrLn $ gao n a b

gao n a b = unlines $ sort $ concat $ d : e where
	m = sum (map length a) * 2 `div` n
	c = fmap sort $ accumArray (flip (:)) [] (1, m) $ map (\i -> (length i, i)) a
	d = if odd m then [] else f $ c!(div m 2)
	e = [zipWith (\i j -> min (i ++ b ++ j) (j ++ b ++ i)) (c!i) (c!(m - i))| i <- [1 .. div (m - 1) 2]]
	f [] = []
	f (x:y:z) = (x ++ b ++ y) : f z

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--271630 	Jan 31, 2011 9:28:31 PM 	watashi 	58D - Calendar 	Haskell 	Accepted 	90 ms 	6700 KB 
