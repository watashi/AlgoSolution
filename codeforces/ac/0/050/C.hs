import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao a = 4 + sum [maximum (map f a) | f <- [sum, foldl1 (-), foldl1 subtract, negate . sum]]
main = do C.interact $ C.pack . show . gao . map (map (fst . fromJust . C.readInt) . C.words) . tail . C.lines

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
2511269 	Nov 5, 2012 5:59:27 PM 	watashi 	50C - Happy Farm 5 	Haskell 	Accepted 	140 ms 	9800 KB
-}
