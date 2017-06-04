main :: IO ()
main = do
  a <- getBigInt
  b <- getBigInt
  let ans = gcd a b `rem` 1000000007 :: Integer
  print ans
  where
  getBigInt = do
    _ <- getLine
    a <- fmap (map read . words) getLine
    return $ product a