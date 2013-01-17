import Data.List

main :: IO ()
main = do
  [n, k] <- fmap (map read . words) getLine
  a <- fmap (reverse . sort . map read . words) getLine
  if k == 0 then p $ succ $ a!!0
  else if k <= n then p $ a!!(k-1)
  else putStrLn "-1"
  where
    p :: Int -> IO ()
    p x = putStrLn $ show x ++ " " ++ show x
