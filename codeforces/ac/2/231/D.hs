readArray = fmap (map read . words) getLine

gao p q i x v = if x (p!!i) (q!!i) then v else 0

main = do
  p <- readArray
  q <- readArray
  a <- readArray
  print $ sum $ zipWith3 (gao (p ++ p) (0:0:0:q)) [1, 4, 2, 5, 0, 3] [(<), (>), (<), (>), (<), (>)] a
