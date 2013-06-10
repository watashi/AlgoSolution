import Data.IntSet

main = putStrLn $ show $ foldl (\s x -> s + toInteger x) zero $ toAscList $ primes limit
	where
		zero = 0 :: Integer
		limit = 2000000

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

