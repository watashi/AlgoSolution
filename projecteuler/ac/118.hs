import Data.List
import Primes

digits = "123456789"

primeList = [p | p <- map show $ primesToN 10000, p \\ digits == ""]

gao d p = concat more ++ one
  where
    n = length d
    more = [map (i:) $ gao (d \\ i) q |
      (i:q) <- init $ tails p,
      length i <= n `div` 2,
      i \\ d == ""]
    one =
      if read d `mod` 3 == 0 then
        []
      else if n <= 4 then
        [[i] | i <- p, sort i == sort d]
      else
        [[i] | i <- permutations d, isPrime $ read i]

main = print $ length $ gao digits primeList

-- ./118  6.99s user 0.16s system 89% cpu 7.975 total
