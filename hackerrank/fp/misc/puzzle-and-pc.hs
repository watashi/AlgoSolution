gao :: Int -> (Int, Int) -> [[Int]]
gao 1 _ = []
gao n (a, b) = center:
  [ zipWith (+) i $ cycle [dx, dy]
  | (x, dx) <- [(m, 0), (m + 1, m)]
  , (y, dy) <- [(m, 0), (m + 1, m)]
  , let (u, v) = if bad (x, y) then (a, b) else (x, y)
  , i <- gao m (if u > m then u - m else u, if v > m then v - m else v)
  ]
  where
  m = n `quot` 2
  bad (x, y) = (x <= m) == (a <= m) && (y <= m) == (b <= m)
  center = concat
    [ [x, y]
    | x <- [m, m + 1]
    , y <- [m, m + 1]
    , not $ bad (x, y)
    ]

main :: IO ()
main = do
  (n:a:b:_) <- fmap (map read . words) getContents
  mapM_ (putStrLn . unwords . map show) $ gao (2 ^ n) (a, b)
    