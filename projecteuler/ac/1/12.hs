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

factors n = factors' n 1 primeList
	where factors' n k ps@(p:s)
		| mod n p == 0	= factors' (div n p) (k + 1) ps
		| n == 1		= k
		| p * p > n		= k * 2
		| otherwise		= k * factors' n 1 s

main = do
	putStrLn $ show $ head $ dropWhile (\x -> factors x <= 500) $ scanl1 (+) [1 ..]

