main :: IO ()
main = do
  n <- readLn
  let ans = take n $ iterate (\i -> zipWith (+) (0:i) (i ++ [0])) [1]
  mapM_ (putStrLn . unwords . map show) ans