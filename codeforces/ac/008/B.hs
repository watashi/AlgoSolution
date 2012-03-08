import Control.Arrow

f p = let n = length p in last $ "OK" : ["BUG" | i <- [1 .. n - 1], (a, b) <- [p!!i], (c, d) <- take (i - 1) p, abs (a - c) + abs (b - d) <= 1]

g d = case d of
	'L' -> id *** pred
	'R' -> id *** succ
	'U' -> succ *** id
	'D' -> pred *** id

main = do getLine >>= putStrLn . f . scanl (flip g) (0, 0)

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--272512 	Feb 1, 2011 2:29:51 PM 	watashi 	8B - Obsession with Robots 	Haskell 	Accepted 	30 ms 	1500 KB 

