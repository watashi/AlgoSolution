import Control.Monad
import Data.List

explode' i x = take i . map (take x) . iterate (drop x)
explode i x j y = concatMap (map (map head) . take j . iterate (map tail)) . explode' i x . map (explode' j y)
rotate = reverse . transpose
std = minimum . take 4 . iterate rotate

gao r c s = [[x * y, x, y] |
	x <- [1 .. r], i <- [div r x], i * x == r,
	y <- [1 .. c], j <- [div c y], j * y == c,
	(==i*j) $ length $ group $ sort $ map std $ explode i x j y s]

main = do
	[r, c] <- fmap (map read . words) getLine
	s <- replicateM r getLine
	putStrLn $ let a = gao r c s in unwords $ map show $ (length a:) $ tail $ minimum a 

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
248456 	Jan 13, 2011 5:59:34 PM 	watashi 	54B - Cutting Jigsaw Puzzle 	Haskell 	Accepted 	30 ms 	1600 KB
-}
