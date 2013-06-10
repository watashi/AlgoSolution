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

primeList = toAscList $ primes 10000

sumFactors n = sumFactors' n [1] primeList - n
	where sumFactors' n k ps@(p:s)
		| mod n p == 0	= sumFactors' (div n p) (head k * p : k) ps
		| n == 1		= sum k
		| p * p > n		= sum k * (n + 1)
		| otherwise		= sum k * sumFactors' n [1] s

main = do
	putStrLn $ show $ sum $ Prelude.filter gao [2 .. 10000]
		where
			gao x = y /= x && z == x
				where
				  	y = sumFactors x
					z = sumFactors y

