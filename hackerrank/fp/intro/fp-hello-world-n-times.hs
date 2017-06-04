main = do
  n <- readLn
  putStr $ unlines $ replicate n "Hello World"