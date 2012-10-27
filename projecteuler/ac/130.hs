import NumberTheory
import Primes

-- copy from 129.hs
repuintMod n m
  | n == 0    = 0
  | odd n     = mod (repuintMod (pred n) m * 10 + 1) m
  | otherwise = let n' = div n 2 in mod (repuintMod n' m * (powMod 10 n' m + 1)) m

main = print $ sum $ take 25 $ [i |
  i <- [2 ..],
  not $ isPrime i,
  gcd i 10 == 1,
  repuintMod (i-1) i == 0]

