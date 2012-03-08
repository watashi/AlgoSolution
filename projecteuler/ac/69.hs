import Data.Array (listArray, (!), assocs)
import Data.IntSet (fromAscList, toAscList, (\\), member)
import Data.Ratio ((%))
import Data.List (foldl1')

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

primeList = map toInteger $ toAscList $ primes 1024

minFactor n = if p * p > n then n else p
	where p = head $ dropWhile (\x -> x * x <= n && n `mod` x /= 0) primeList

phi m = phis
	where
		phis = listArray (1, m) $ 1 : [phi' i | i <- [2 .. m]]
		phi' n = (phis ! q) * r
			where
				p = minFactor n
				q = n `div` p
				r = if q `mod` p == 0 then p else p - 1
		
main = putStrLn $ show $ foldl1' max $ map (\(n, d) -> (n % d, n)) $ assocs $ phi 1000000
	
-- ans := 2 * 3 * 5 * 7 * 11 * 13 * 17

