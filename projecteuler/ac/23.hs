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

primeList = toAscList $ primes 200

sumFactors n = sumFactors' n [1] primeList - n
	where sumFactors' n k ps@(p:s)
		| mod n p == 0	= sumFactors' (div n p) (head k * p : k) ps
		| n == 1		= sum k
		| p * p > n		= sum k * (n + 1)
		| otherwise		= sum k * sumFactors' n [1] s

abundantList = Prelude.filter (\x -> sumFactors x > x) [1 .. 28123]
abundantMap = fromAscList abundantList

main = putStrLn $ show $ sum $ Prelude.filter (not . ok) [1 .. 28123]
	where ok n = ok' abundantList
		where ok' (x:xs) = x < n && (member (n - x) abundantMap || ok' xs)

