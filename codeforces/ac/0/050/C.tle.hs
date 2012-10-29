main = do interact $ show . gao . map (map read . words) . tail . lines
gao a = 4 + sum [maximum (map f a) | f <- [sum, foldl1 (-), (\[x,y]->y-x), negate . sum]]

{-
	2 * (max{x} - min{x})
	2 * (max{y} - min{y})
	-|max{x} + max{y} - max{x + y}|
	-|min{x + y} - min{x} - min{y}|
	-|max{x} - min{y} - max{x - y}|
	-|max{y} - min{x} - max{y - x}|
=	max{x+y}+max{x-y}+max{y-x}+max{-x-y}
-}-}
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229404 	Dec 24, 2010 11:07:18 AM 	watashi 	C - Happy Farm 5 	Haskell 	Time limit exceeded on test 69 	2000 ms 	14888 KB 
-}
