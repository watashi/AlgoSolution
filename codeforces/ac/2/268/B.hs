main :: IO ()
main = do
  n <- fmap read getLine
  print $ sum [(i - 1) * (n - i) + i | i <- [1 :: Integer .. n]]
