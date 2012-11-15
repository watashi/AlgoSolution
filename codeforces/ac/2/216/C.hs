gao n m k = takeWhile (<=m) $ concat $ iterate next $ all 1
  where
    all = replicate k
    next a = zipWith (+) (n-1: repeat n) $ all $ maximum a

main = do
  [n, m, k] <- fmap (map read . words) getLine
  let a = gao n (n+m) k
  print $ length a
  putStrLn $ unwords $ map show a

