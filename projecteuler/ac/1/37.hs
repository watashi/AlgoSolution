import Data.List (inits, tails)
import Data.IntSet (fromAscList, toAscList, member, (\\))

primes n = sieve 2 (fromAscList [2 .. n])
	where sieve p s = if p * p > n then s else sieve (next (p + 1) s) (mark p s)
		where
			next p s = if member p s then p else next (p + 1) s
			mark p s = s \\ (fromAscList $ takeWhile (<=n) $ map (p*) $ [p ..])

primeSet = primes 1000000
primeList = toAscList primeSet
isPrime p = member p primeSet

main = putStrLn $ show $ sum $ filter (truncatablePrime . show) $ dropWhile (<10) $ primeList
	where truncatablePrime x = foldr1 (&&) $ map (isPrime . read) $ (init $ tails x) ++ (tail $ inits x)

