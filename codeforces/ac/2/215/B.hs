main = do
  r1 <- fmap (maximum . tail) getArray
  p1 <- fmap (maximum . tail) getArray
  p2 <- fmap (minimum . tail) getArray
  [a, b] <- getArray
  print $ gao r1 p1 p2 a b
  where
    getArray = fmap (map read . words) getLine
    gao r1 p1 p2 a b = r1 / sqrt ((a * p2) / (b * p1) + 1)
