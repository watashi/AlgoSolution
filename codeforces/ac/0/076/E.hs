import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

readInt = fst . fromJust . C.readInteger

main = do
	(h:t) <- fmap C.lines $ C.hGetContents stdin
	let
		n = readInt h
		a = map (map readInt . C.words) t
	print $ let x = map head a; y = map last a in gao n x + gao n y

gao n x = toInteger n * sum (map (^2) x) - (sum x) ^ 2

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
408669 	Apr 27, 2011 6:20:36 PM 	watashi 	76E - Points 	Haskell 	Accepted 	200 ms 	21500 KB 
-}
