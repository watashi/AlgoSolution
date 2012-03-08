import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

main = do C.hGetContents stdin >>= putStr . show . gao . map (fst . fromJust . C.readInt) . C.words where
	gao (n:a) = n - maximum [length $ filter (==i) a | i <- [1 .. 3]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241333 	Jan 7, 2011 7:14:39 PM 	watashi 	52A - 123-sequence 	Haskell 	Accepted 	270 ms 	25140 KB 
-}

{-
main = do interact (show . gao . map read . words) where
	gao (n:a) = n - maximum [length $ filter (==i) a | i <- [1 .. 3]]

# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241334 	Jan 7, 2011 7:15:58 PM 	watashi 	52A - 123-sequence 	Haskell 	Time limit exceeded on test 18 	2000 ms 	9760 KB 
-}



