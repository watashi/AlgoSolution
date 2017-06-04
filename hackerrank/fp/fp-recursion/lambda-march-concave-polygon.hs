import Control.Applicative
import Control.Monad
import Data.List

data PointT a = Point {-# UNPACK #-} !a {-# UNPACK #-} !a
  deriving (Eq, Ord, Show)

instance Functor PointT where
  f `fmap` Point x y = Point (f x) (f y)

instance Applicative PointT where
  pure i = Point i i
  Point f g <*> Point x y = Point (f x) (g y)

instance Num a => Num (PointT a) where
  (+) = liftA2 (+)
  (-) = liftA2 (-)
  (*) = liftA2 (*)
  abs = fmap abs
  negate = fmap negate
  signum = fmap signum
  fromInteger = pure . fromInteger

infixl 7 `dot`, `cross`

dot, cross :: Num a => PointT a -> PointT a -> a
dot (Point x1 y1) (Point x2 y2) = x1 * x2 + y1 * y2
cross (Point x1 y1) (Point x2 y2) = x1 * y2 - y1 * x2

convexHull :: (Num a, Ord a) => [PointT a] -> [PointT a]
convexHull p = d ++ u
  where
  q = sort p
  (_:d) = let (h:t) = q in foldl' go [h] t
  (_:u) = let (h:t) = reverse q in foldl' go [h] t
  go is i = i: until convex tail is
    where
    convex (j:k:_) = (i - j) `cross` (k - j) >= 0
    convex _ = True

type Point = PointT Int

main :: IO ()
main = do
  n <- readLn
  p <- replicateM n $ do
    (x:y:_) <- map read . words <$> getLine
    return $ Point x y
  let q = convexHull p :: [Point]
  putStrLn $ if sort p == sort q then "NO" else "YES"