import qualified Data.ByteString.Lazy.Char8 as C
import Data.Maybe
import IO

powMod _ 0 m = mod 1 m
powMod a b m = mod (if odd b then powMod a (pred b) m * a else powMod a (div b 2) m ^ 2) m

phi n = phi' n n [2 ..] where
	phi' 1 m _ = m
	phi' n m (p:q)
		| p * p > n		= m * (n - 1) `div` n
		| mod n p == 0	= phi' (until ((/=0) . (`mod`p)) (`div`p) n) (m * (p - 1) `div` p) q
		| otherwise		= phi' n m q

gao a b c = if r > 0 then r else c where
	n = phi c
	t = powMod b (if a > c then n + mod (a - 1) n else a - 1) c
	r = (b - 1) * t `mod` c

main = do
	[b, n, c] <- fmap (map (fst . fromJust . C.readInteger) . C.words) (C.hGetContents stdin)
	putStrLn $ show $ gao n b c

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--286131 	Feb 16, 2011 7:38:44 PM 	watashi 	17D - Notepad 	Haskell 	Accepted 	1060 ms 	11900 KB 

