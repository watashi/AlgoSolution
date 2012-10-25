import Primes

limit = 4000000

primeList = map toInteger $ primesToN 100

find n = gao primeList 18 (2*n) 1 (10^18)
  where
    gao _ _ 1 x y = min x y
    gao (p:q) r n x y
      | x >= y    = y
      | otherwise = foldl (\i j -> gao q j (ceiling n $ 2 * j + 1) (x * p ^ j) i) y [1 .. r]
      where
        ceiling a b = div (a + b - 1) b

main = print $ find limit
