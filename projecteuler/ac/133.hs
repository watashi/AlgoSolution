import NumberTheory
import Primes

-- @see 129.hs
loopLen n
  | mod n 3 == 0  = m `div` 2 * 3
  | otherwise     = m
  where
    m = eulerTotient n

repunitMod n m
  | n == 0    = 0
  | odd n     = mod (repunitMod (pred n) m * 10 + 1) m
  | otherwise = let n' = div n 2 in mod (repunitMod n' m * (powMod 10 n' m + 1)) m

minLoopLen n = go $ loopLen n
  where
    go m
      | null m'   = m
      | otherwise = go $ foldr1 gcd m'
      where
        m' = [q | (p, r) <- primeDivision m, q <- [div m p], repunitMod q n == 0]

finite 1 = True
finite n = g /= 1 && finite (div n g)
  where
    g = gcd n 10

infinite = not . finite

main = print $ sum [p | p <- primesToN 100000, gcd p 10 /= 1 || infinite (minLoopLen p)]
