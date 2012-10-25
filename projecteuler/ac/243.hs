import Data.Ratio
import Primes

limit = 15499 % 94744

primeList = map toInteger $ primesToN 10000

gao x = go phi
  where
    phi = scanl (\(r, n) i -> (r * (pred i % i), n * i)) (1%1,1) $ primeList
    go ((r,n):t)
      | r >= x    = go t
      | m == 1    = n
      | otherwise = min (m * n) $ go t
      where
        n' = max n $ succ $ floor $ x / (x - r)
        m = div (n' + n - 1) n

main = print $ gao limit
