import Data.Array (listArray, (!), elems)
import Data.IntSet (fromAscList, toAscList, (\\), member)

primes n = sieve 2 (fromAscList [2 .. n])
	where sieve p s
		| p * p > n = s
		| otherwise = sieve (next (p + 1) s) (mark p s)
			where
				next p s
					| member p s = p
					| otherwise = next (p + 1) s
				mark p s =
					s \\ (fromAscList $ takeWhile (<=n) $ map (p*) $ [p ..])

primeList = map toInteger $ toAscList $ primes 100

limit = 10 ^ 9

hamming [] = [1]
hamming (p:ps) = concat [takeWhile (<=limit) $ map (*q) $ scanl (*) 1 $ repeat p | q <- hamming ps]

main = do putStrLn $ show $ length $ hamming primeList

