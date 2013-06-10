import Enumeration
import NumberTheory
import Primes

limit = 1000000

primeList = dropWhile (<5) $ primesToN $ nextPrime limit

gao a b = mod x b * t + a
  where
    t = until (>a) (*10) 1
    x = modInv b t * (b - a)

main = do
  print $ sum $ map (uncurry gao) $ pairs primeList

