{-
0 * 10 + 1 => 1
1 * 10 + 1 => mod 11 n
....
? * 10 + 1 => 0

== n % 10 = 1

== n % 10 = 3
== n % 10 = 7
== n % 10 = 9

minLoopLen n | loopLen n
-}

import NumberTheory
import Primes

limit = 1000000

minLoopLen n = snd $ until ((==0) . fst) (\(i, j) -> (mod (i * 10 + 1) n, succ j)) (1, 1)

loopLen n
  | mod n 3 == 0  = m `div` 2 * 3
  | otherwise     = m
  where
    m = eulerTotient n

repuintMod n m
  | n == 0    = 0
  | odd n     = mod (repuintMod (pred n) m * 10 + 1) m
  | otherwise = let n' = div n 2 in mod (repuintMod n' m * (powMod 10 n' m + 1)) m

main = print $ take 100 $ [(i, j) |
  i <- [limit ..],
  gcd i 10 == 1,
  j <- [loopLen i],
  foldr1 (&&) $ map ((/=0) . (`repuintMod` i) . (div j) . fst) $ primeDivision j]

{-
A(n) = read $ replicate n '1'
A(n) % m = 0
(10 ^ n) % (9 * A(n)) = 1
(10 ^ n) = 1 (mod 9A(n))
== gcd(m, 3) == 0
(10 ^ n) = 1 (mod m)
== gcd(m, 3) != 0
(10 ^ n) = 1 (mod 9m) <= this is where 3 from!!

[quote src="http://projecteuler.net/problem=130"]
You are given that for all primes, p > 5, that p − 1 is divisible by A(p).
[/quote]
-}
