import Control.Applicative
import Control.Monad

area :: [(Double, Double)] -> Double
area p = sum $ zipWith dist p (tail p ++ [head p])
  where
  dist (x1, y1) (x2, y2) = sqrt (dx * dx + dy * dy)
    where
    dx = x2 - x1
    dy = y2 - y1

main :: IO ()
main = do
  n <- readLn
  p <- replicateM n $ do
    (x:y:_) <- map read . words <$> getLine
    return (x, y)
  print $ area p