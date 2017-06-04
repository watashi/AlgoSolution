main :: IO ()
main = do
  a <- getLine
  b <- getLine
  putStrLn $ concat $ zipWith (\i j -> [i, j]) a b