main = do
  a <- fmap (map read . lines) getContents
  putStr $ unlines $ map show $ f a
  where
  f (i: j: k) = j: f k
  f _ = [] :: [Int]