main :: IO ()
main = do
  re <- read <$> getLine
  flip mapM_ [1::Int .. re] $ \ri -> do
    (k:c:s:_) <- map read . words <$> getLine
    let k' = toInteger k
        ans =
          [ succ $ foldl1 (\i j -> i * k' + j)  $ take c d
          | d <- takeWhile (not . null) $ iterate (drop c) [0 .. k' - 1]
          ]
    putStrLn $ "Case #" ++ show ri ++ ": " ++
      (if length ans > s then "IMPOSSIBLE" else unwords $ map show ans)
