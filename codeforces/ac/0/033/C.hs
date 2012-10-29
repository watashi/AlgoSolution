import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

main = do C.hGetContents stdin >>= putStrLn . show . gao . map (fst . fromJust . C.readInt) . tail . C.words

gao a = (sum a -) $ (2*) $ minimum $ zipWith (+) (f a) $ reverse $ f $ reverse a where
	f = scanl1 min . scanl (+) 0

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
242472 	Jan 8, 2011 10:44:41 PM 	watashi 	C - Wonderful Randomized Sum 	Haskell 	Accepted 	140 ms 	15908 KB
242468 	Jan 8, 2011 10:41:44 PM 	watashi 	C - Wonderful Randomized Sum 	Haskell 	Time limit exceeded on test 14 	2000 ms 	35412 KB 
-}
