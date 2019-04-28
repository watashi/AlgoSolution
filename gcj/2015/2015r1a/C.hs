import Control.Monad
import Data.List
import Data.Ratio

data Point = Point
  { _x :: Integer -- oops, int64 * int64 -> overflow
  , _y :: Integer
  } deriving (Eq, Show)

arg :: Point -> Point -> Rational
arg (Point x1 y1) (Point x2 y2) = arg' (x2 - x1) (y2 - y1)
  where
  arg' x y
    | x < 0 = 2 - arg' (-x) y                   -- (1, 3)
    | otherwise = (y * abs y) % (x * x + y * y) -- [-1, 1]

gao :: [Rational] -> Int
gao a = minimum $ scanl (+) c $ map snd b
  where
  b = sort $ concat [[(i, -1), (if i < 1 then i + 2 else i - 2, 1)] | i <- a]
  c = length $ filter (\i -> -1 <= i && i < 1) a

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- read <$> getLine
    a <- replicateM n $ do
      (x:y:_) <- map read . words <$> getLine
      return $ Point x y
    putStrLn $ "Case #" ++ show ri ++ ":"
    forM_ a $ \i -> do
      let b = [arg j i | j <- a, i /= j]
      print $ gao b
