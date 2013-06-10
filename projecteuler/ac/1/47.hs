import Data.Array
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

primeList = toAscList $ primes 1024

distinctFactors n = distinctFactors' n primeList
	where distinctFactors' n ps@(p:s)
		| n == 1		= 0
		| p * p > n		= 1
		| mod n p == 0	= 1 + distinctFactors' (until (\x -> mod x p /= 0) (`div` p) n) ps
		| otherwise		= distinctFactors' n s

main = putStrLn $ show $ k
	where
		a = listArray (2, 1000000) [distinctFactors i | i <- [2 ..]];
		k = head $ dropWhile (\i -> a!i /= 4 || a!(i+1) /= 4 || a!(i+2) /= 4 || a!(i+3) /= 4) [2 ..]

-- 134043
