import Control.Monad
import Data.List

main = do
	n <- fmap read getLine
	a <- replicateM (3*n-1) getLine
	putStrLn $ show $ length $ group $ sort $ gao a where
		gao [] = []
		gao (a:b:s) = c: gao (drop 1 s) where
			c = minimum $ take 4 $ iterate (\(h:t) -> t ++ [h]) $ a ++ reverse b

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235156 	Dec 29, 2010 10:43:33 PM 	watashi 	A - Cheaterius's Problem 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
