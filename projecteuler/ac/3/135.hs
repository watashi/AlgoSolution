{-
  (r+s)^2 - r^2 - (r-s)^2
= 4rs - r^2
= r(4s - r)
-}

import Primes

solutions n = [(s, r) | r <- divisors n, (s, t) <- [divMod (r + div n r) 4], t == 0, s < r]

main = print $ length [i | i <- [27 .. 1000000], length (solutions i) == 10]

-- ./135  11.40s user 0.12s system 98% cpu 11.660 total

