import Data.List

factorial n = if n == 0 then 1 else n * factorial (n - 1)
permutation k [] = []
permutation k a = a!!i : permutation j (a \\ [a!!i])
	where
		(i, j) =  divMod k $ factorial  $ length a - 1

main = putStrLn $ concat $ map show $ permutation 999999 [0 .. 9]

