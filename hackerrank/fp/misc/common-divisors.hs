import Control.Monad

divisors :: Int -> [Int]
divisors n = concat
  [ i: [j | i < j]
  | i <- takeWhile (\i -> i * i <= n) [1..]
  , let (j, k) = n `quotRem` i
  , k == 0
  ]

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    (a:b:_) <- fmap (map read . words) getLine
    print $ length $ divisors $ gcd a b