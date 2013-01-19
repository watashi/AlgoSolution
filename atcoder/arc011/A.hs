main :: IO ()
main = do
  [m, n, x] <- fmap (map read . words) getLine
  let gao a b = if a == 0 then 0 else a + gao (c * n) r
        where
          (c, r) = divMod (a + b) m
  print $ gao x (0 :: Integer)
