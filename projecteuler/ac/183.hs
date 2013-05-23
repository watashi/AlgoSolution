import Data.Ratio

-- [(i, i / e)]
parts = iterate (\(i, j) -> (succ i, f (succ i) j)) (1, 1)
  where
    f x y = if (1 + 1 / k) ** k > fromIntegral x / (k + 1) then y else succ y
      where
        k = fromIntegral y

finite 1 = True
finite n = g > 1 && finite (div n g)
  where
    g = gcd n 10

main = print $ sum [if finite (e `div` gcd e i) then -i else i |
  (i, e) <- takeWhile ((<=10000) . fst) parts, i >= 5]
