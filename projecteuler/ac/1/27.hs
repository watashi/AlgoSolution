import Data.List (foldl1')
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
isPrime p = member p primeSet 

main = putStrLn $ show $ foldl1' max $ [(gao a b, a * b) | a <- [-999 .. 999], b <- [-999 .. 999]]
	where gao a b = head $ dropWhile (\x -> isPrime ((x + a) * x + b)) [0 ..]

