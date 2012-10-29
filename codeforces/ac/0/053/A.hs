import Control.Monad
import Data.List

main = do
	s <- getLine
	n <- fmap read getLine
	a <- replicateM n getLine
	putStrLn $ head $ (++[s]) $ sort $ filter (isPrefixOf s) a

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241395 	Jan 7, 2011 8:08:24 PM 	watashi 	53A - Autocomplete 	Haskell 	Accepted 	30 ms 	1564 KB
-}
