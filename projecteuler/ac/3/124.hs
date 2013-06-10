import Data.IntSet
import Data.List(sort)

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

primeList = Prelude.map toInteger $ toAscList $ primes 500

rad n = rad' n primeList
	where rad' n ps@(p:s)
		| p * p > n		= n
		| mod n p == 0	= p * rad' (until (\x -> mod x p /= 0) (`div` p) n) ps
		| otherwise		= rad' n s

main = do
	putStrLn $ show $ last $ take 10000 rads
	where rads = sort $ Prelude.map (\x -> (rad x, x)) [1 .. 100000]

