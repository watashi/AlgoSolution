main = do
  [a, b, c] <- fmap (map read . words) getLine
  print $ ceiling $ ((a - b) * c) / b
