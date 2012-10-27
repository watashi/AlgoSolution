import NumberTheory
import Primes

flatten = concatMap (uncurry $ flip replicate)

factors = scanl (\(i, j) k -> (i * k, k)) (1, 1) . flatten . primeDivision

divides p (i, j) = mod (sum [powMod 10 k p | k <- map (* div i j) [0 .. j - 1]]) p == 0

index p (i, j) = pred $ until (not . (`divides` (i, j)) . (p^)) succ 1

primeFactors sz q = filter ((/=0) . snd) $
  [(p, sum [index p d | d <- factors sz]) | p <- primesToN q]

{-
main = print $ length $ flatten $ primeFactors (10^9) 200000
41
./132  6.00s user 0.10s system 89% cpu 6.813 total
-}

main = print $ sum $ take 40 $ flatten $ primeFactors (10^9) 200000

