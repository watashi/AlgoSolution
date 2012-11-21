main = do
  [p, d] <- fmap (map read . words) getLine
  print $ (p-) $ last $ filter (<=d) $ map (\i -> (p+1) `mod` (10^i)) [0 .. 20]
