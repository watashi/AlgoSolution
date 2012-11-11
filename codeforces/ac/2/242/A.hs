main = do
  [x, y, a, b] <- fmap (map read . words) getLine
  let z = [[i, j] | i <- [a .. x], j <- [b .. y], i > j] :: [[Int]]
  print $ length $ z
  putStr $ unlines $ map (unwords . map show) z
