import Control.Applicative
import Control.Monad
import Control.Parallel.Strategies
import Data.Int
import Data.List

data Point = Point {-# UNPACK #-} !Int64 {-# UNPACK #-} !Int64
  deriving (Eq, Show)

instance Ord Point where
  compare p1@(Point x1 y1) p2@(Point x2 y2) =
    case compare (quadrant p1) (quadrant p2) of
      EQ -> compare 0 $ x1 * y2 - x2 * y1
      ret -> ret

quadrant :: Point -> Int64
quadrant (Point x y) = if y < 0 then signum x else 3 - signum x

neg :: Point -> Point
neg (Point x y) = Point (-x) (-y)

sub :: Point -> Point -> Point
sub (Point x1 y1) (Point x2 y2) = Point (x1 - x2) (y1 - y2)

gao :: [Point] -> Int
gao a = minimum $ scanl (+) c $ map snd b
  where
  b = sort $ concat [[(i, -1), (neg i, 1)] | i <- a]
  c = length $ filter (\(Point x y) -> y < 0 || (y == 0 && x > 0)) a

main :: IO ()
main = do
  re <- read <$> getLine
  inputs <- replicateM re $ do
    n <- read <$> getLine
    replicateM n $ do
      (x:y:_) <- map read . words <$> getLine
      return $ Point x y
  let outputs = runEval $ parList rdeepseq $ flip map inputs $ \a ->
        [gao [i `sub` j | j <- a, i /= j] | i <- a]
  forM_ (zip [1::Int .. re] outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ":"
    mapM_ print ans
