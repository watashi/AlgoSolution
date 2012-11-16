main = do
  getLine
  a <- fmap (map read . words) getLine
  getLine
  b <- fmap (map read . words) getLine
  print $ gao a b
  where
    gao a b = length $ filter (==maximum c) c
      where
        c = [div j i | i <- a, j <- b, mod j i == 0]
