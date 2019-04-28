main :: IO ()
main = do
  re <- read <$> getLine
  flip mapM_ [1::Int .. re] $ \ri -> do
    s <- filter (`elem` "+-") <$> getLine
    let ans = length $ filter id $ zipWith (/=) s (tail s ++ "+")
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
