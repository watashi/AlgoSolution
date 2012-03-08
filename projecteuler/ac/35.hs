import Data.IntSet (fromAscList, toAscList, member, (\\))

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

primeSet = primes 1000000
primeList = toAscList primeSet
isPrime p = member p primeSet

main = putStrLn $ show $ length $ filter (circularPrime . show) $ primeList
	where circularPrime x =
		foldr1 (&&) $ map (isPrime . read) $ take (length x) $ iterate (\l -> last l : init l) x



