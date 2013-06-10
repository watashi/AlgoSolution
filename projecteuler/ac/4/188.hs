import Data.Array (listArray, (!), elems)
import Data.IntSet (fromAscList, toAscList, (\\), member)

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

primeList = map toInteger $ toAscList $ primes 10000

{- hyperexponentiation /or/ tetration -}

phi 1 = 1
phi n = foldl (\a b -> a `div` b * pred b) n $ filter ((== 0) . (n `mod`)) $ takeWhile (<=n) primeList

powMod a b m = powMod' b
    where
    powMod' 0 = 1 `mod` m
    powMod' n
        | even n        = p * p `mod` m
        | otherwise     = p * p * a `mod` m
        where p = powMod' (n `div` 2)

tetration a b 1 = 0
tetration a 1 m = mod a m
tetration a b m = let m' = phi m in powMod a (m' + tetration a (pred b) m') m

main = putStrLn $ show $ tetration 1777 1855 (10 ^ 8)

