main :: IO ()
main = do
  n <- fmap (minimum . map read . words) getLine
  print $ n + 1
  putStr $ unlines $ [show i ++ " " ++ show (n - i) | i <- [0 :: Int .. n]]
