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

primeSet = primes 100000
compositeList = toAscList $ fromAscList [3, 5 .. 100000] \\ primeSet
isPrime p = member p primeSet

main = putStrLn $ show $ head $ dropWhile valid compositeList
	where
		valid n = (>0) $ head $ dropWhile (\x -> x > 0 && (not . isPrime) x) [n - 2 * i * i | i <- [1 ..]]

-- 5777
