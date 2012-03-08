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

-- primeList = map toInteger $ toAscList $ primes 100000

gao [] = 1 : repeat 0
gao (p:ps) = b
	where
		a = gao ps
		b = [a !! i + if i < p then 0 else b !! (i - p) | i <- [0 .. ]]

main = do putStrLn $ show $ length $ takeWhile (<= 5000) $ gao $ toAscList $ primes 1024

