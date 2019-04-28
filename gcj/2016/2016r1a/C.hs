import Data.Array.IArray
import Data.Foldable
import Data.Graph

main :: IO ()
main = do
  re <- read <$> getLine
  flip mapM_ [1::Int .. re] $ \ri -> do
    n <- read <$> getLine
    f <- map read . words <$> getLine
    let g = buildG (1, n) $ f `zip` [1 ..]
        s = map toList $ scc g
        ans = circle `max` pairs
        circle = maximum $ map length s
        pairs = sum [go u v + go v u | [u, v] <- s]
          where
          go v p = succ $ maximum $ 0: [go i 0 | i <- g!v, i /= p]
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
