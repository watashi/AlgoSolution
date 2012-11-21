main = do
  n <- fmap read getLine
  if n <= 2
    then print $ -1
    else putStrLn $ unwords $ map show $ [2 .. n] ++ [1]
