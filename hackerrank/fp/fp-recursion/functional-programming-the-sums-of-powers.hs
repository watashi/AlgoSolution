gao :: Int -> Int -> [Integer]
gao m n = foldl f (1: repeat 0) [1..m]
  where
  -- f i j = let k = zipWith (+) i $ replicate (j^n) 0 ++ k in k
  f i j = zipWith (+) i $ replicate (j^n) 0 ++ i

main :: IO ()
main = do
  x <- readLn
  n <- readLn
  let m = pred $ until (\i -> i^n > x) succ 0
  print $ gao m n !! x