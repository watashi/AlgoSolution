main = do
  getLine
  p <- fmap (map read . words) getLine
  q <- fmap (reverse . map read . words) getLine
  let (x, y) = foldl (gao q) (repeat 0, 0) p
  putStrLn $ unwords $ map show $ reverse x ++ [y]

gao q (c, s) t = let (x, y) = go q c [] (s+t) in (reverse x, y)

go [] _ x y = (x, y)
go (a:as) (b:bs) x y = let c = y `div` a in go as bs (b+c:x) (y `mod` a)
