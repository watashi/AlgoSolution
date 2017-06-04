main :: IO ()
main = do
  (a:b:_) <- fmap (map read . words) getLine
  let n = a * b
  print $ sum [n / i | i <- [1..n]]