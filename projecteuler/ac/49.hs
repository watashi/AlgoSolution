import Data.IntSet (fromAscList, toAscList, member, (\\))
import Data.List (sort)

primes n = sieve 2 (fromAscList [2 .. n])
	where sieve p s = if p * p > n then s else sieve (next (p + 1) s) (mark p s)
		where
			next p s = if member p s then p else next (p + 1) s
			mark p s = s \\ (fromAscList $ takeWhile (<=n) $ map (p*) $ [p ..])

primeSet = primes 10000
primeList = toAscList primeSet
isPrime p = member p primeSet

main = putStrLn $ show $ filter (\(a, b, c) -> isPrime c && ss a == ss c && ss b == ss c) $
	[(a, b, 2 * b - a) | i <- [s .. t - 1], j <- [i + 1 .. t - 1], let a = primeList!!i; b = primeList!!j]
	where
		s = length $ takeWhile (<1000) $ primeList
		t = length $ primeList
		ss = sort . show

