import Data.IntSet (fromAscList, toAscList, member, (\\))
import Data.List (sort, foldl1')

primes n = sieve 2 (fromAscList [2 .. n])
	where sieve p s = if p * p > n then s else sieve (next (p + 1) s) (mark p s)
		where
			next p s = if member p s then p else next (p + 1) s
			mark p s = s \\ (fromAscList $ takeWhile (<=n) $ map (p*) $ [p ..])

primeSet = primes 1000000
primeList = toAscList primeSet
isPrime p = member p primeSet

gao [] = (0, -1)
gao p@(p0:ps) = foldl1' (max) $ gao ps : (filter (isPrime .snd) $ zip [2..] $ takeWhile (<1000000) $ scanl1 (+) $ p)

main = putStrLn $ show $ gao primeList
