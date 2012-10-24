cnt x y = sum [1 | i <- x, j <- x, y (i + j)]

pure n
  | odd n     = 0
  | otherwise = a * b ^ (pred m)
  where
    m = div n 2
    a = cnt [1 .. 9] (\i -> odd i && i < 10)
    b = cnt [0 .. 9] (\i -> odd i && i < 10)

zebra n
  | mod n 4 == 3 = 5 * a ^ (succ m) * b ^ m
  | otherwise    = 0
  where
    m = div n 4
    a = cnt [1 .. 9] (\i -> odd i && i >= 10)
    b = cnt [0 .. 9] (\i -> even i && i < 10)

main = do
  print $ sum [pure n + zebra n | n <- [1..9]]
