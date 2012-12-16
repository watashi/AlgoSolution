import Control.Monad

gao :: Int -> Int -> Int -> [Int] -> Int
gao n a b c = go n c
  where
    go _ [] = 1
    go x (h:t) = if y < h then 1 else 1 + go (y - h) t
      where
        y = if x <= a then x + b else x

main :: IO ()
main = do
  [n, m, a, b] <- fmap (map read . words) getLine
  c <- replicateM m $ fmap read getLine
  let ans = gao n a b c
  if ans > length c
    then putStrLn "complete"
    else print ans
