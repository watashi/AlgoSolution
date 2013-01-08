gao :: Int -> Int -> Int
gao a b = 2 * c + diff a' b'
  where
    c = min a b `div` 2
    a' = a - 2 * c
    b' = b - 2 * c
    same 0 y = max 0 $ y - 1
    same x y = 1 + diff y (x - 1)
    diff 0 y = y
    diff x y = same (x - 1) y

main :: IO ()
main = do
  [n, m] <- fmap (map read . words) getLine
  let x = max (gao m $ n - 1) (gao n $ m - 1)
  print $ x
  print $ n + m - 1 - x
