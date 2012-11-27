go [] = []
go [a] = [a]
go (a:b:c) = b:go c

main = do
  n <- fmap read getLine
  a <- fmap (map read . words) getLine
  let b = go $ map fst $ filter ((<0) . snd) $ zip [1 ..] a
      c = if null b then [n] else init b ++ [n]
  print $ length c
  putStrLn $ unwords $ map show $ zipWith (-) c $ 0:c
