main = do
  x@[a, b, c] <- fmap (map read . words) getLine
  print $ a * b + b * c + c * a - sum x + 1
