{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad

main :: IO ()
main = do
  [n, m, r'] <- fmap (map read . words) getLine
  let r = fromIntegral r' :: Double
  road <- replicateM n $ do
    [a, b, c] <- fmap (map read . words) getLine
    let d = sqrt $ a * a + b * b
    return $ \(x, y) -> abs $ (a / d) * (r * x) + (b / d) * (r * y) + (c / d)
  point <- replicateM m $ do
    [p, q] <- fmap (map read . words) getLine
    return $ \(x, y) -> (r * x - p) ** 2 + (r * y - q) ** 2
  let eval xy = minimum [i xy | i <- road] + minimum [i xy | i <- point]
      neighbour step x = filter (\i -> abs i <= 1) $ map (\i -> x + i * step) [-2 .. 2]
      move (x, y) step = snd $ maximum [(eval z, z) |
        x' <- neighbour step x, y' <- neighbour step y, let z = (x', y')]
  ans <- liftM maximum $ forM pos $ \x ->
    liftM maximum $ forM pos $ \y ->
      return $ eval $ foldl move (x, y) steps
  print $ ans
  where
    pos = map (*0.1) [-10 .. 10]
    steps = take 64 $ iterate (*0.75) 0.05
