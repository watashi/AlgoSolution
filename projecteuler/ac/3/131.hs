{-
n^2(n+p) = m^3

== gcd(n, p) = p
n = p^r*q
n^2(n+p) = p^(2r+1) * q^2 * (p^(r-1)*q+1)
r = 3k+1, q = u^3v
p^(r-1)*q + 1 = (p^k*u^v)^3 + 1
NO SOLUTION

== gcd(n, p) = 1
gcd(n^2, n+p) = 1
n^2 = u^3, n+p = v^3
-}

import Data.IntSet
import Primes

cubes = [i ^ 3 | i <- [1 .. 700]]

primes = fromList $ primesToN 1000000

solutions = fromList $ [k | i <- cubes, j <- cubes, j < i, k <- [i - j], member k primes]

main = print $ size $ solutions
