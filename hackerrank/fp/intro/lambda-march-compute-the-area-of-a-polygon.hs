import Control.Applicative
import Control.Monad

area :: [(Double, Double)] -> Double
area p = sum (zipWith cross p (tail p ++ [head p])) / 2
  where
  cross (x1, y1) (x2, y2) = x1 * y2 - x2 * y1

main :: IO ()
main = do
  n <- readLn
  p <- replicateM n $ do
    (x:y:_) <- map read . words <$> getLine
    return (x, y)
  print $ area p