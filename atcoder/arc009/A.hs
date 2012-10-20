import Control.Monad
main = do
  n <- fmap read getLine
  s <- fmap sum $ replicateM n $ fmap (product . map read . words) getLine
  print $ s + div (s * 5) 100
