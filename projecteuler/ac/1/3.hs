import Data.IntSet

primes n = sieve 2 (fromAscList [2 .. n])
	where sieve p s
		| p * p > n = s
		| otherwise = sieve (next (p + 1) s) (mark p s)
		where
			next p s
				| member p s = p
				| otherwise = next (p + 1) s
			mark p s =
				s \\ (fromAscList $ takeWhile (<=n) $ Prelude.map (p*) $ [p ..])

primeList = Prelude.map toInteger $ toAscList $ primes 10000

primeFactors n = primeFactors' n primeList
	where primeFactors' n ps@(p:s)
		| n == 1		= []
		| p * p > n		= [n]
		| mod n p == 0	= p : primeFactors' (div n p) ps
		| otherwise		= primeFactors' n s

main = do
	putStrLn $ show $ primeFactors 600851475143

