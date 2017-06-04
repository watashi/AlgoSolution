main = do
  _ <- getLine
  a <- fmap (map read . words) getLine
  let ans = foldl1 lcm a :: Integer
  print ans