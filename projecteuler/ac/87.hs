import Data.IntSet (fromAscList, toAscList, (\\), member)
import Data.List (group, sort)

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

primeList = map toInteger $ toAscList $ primes 7200

limit = 50000000
pp k = takeWhile (< limit) [i ^ k | i <- primeList]
answer = map head $ group $ sort $ [a + b + c | a <- pp 2, b <- pp 3, a + b < limit, c <- pp 4, a + b + c < limit]
main = do putStrLn $ show $ length $ answer

