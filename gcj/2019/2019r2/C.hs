import Control.Monad
import Data.Ratio
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C
import Text.Printf

minimumPair :: (Int, Int) -> (Int, Int) -> (Int, Int)
minimumPair (xl, yl) (xr, yr) = go (0, 1) (1, 0)
  where
  go (x1, y1) (x2, y2)
    | x * yl <= y * xl = go (x, y) (x2, y2)
    | x * yr < y * xr = (x, y)
    | otherwise = go (x1, y1) (x, y)
    where
    x = x1 + x2
    y = y1 + y2

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 :: Int .. re] $ \ri -> do
    n <- readInt <$> C.getLine
    points <- replicateM n $ do
      (a:b:_) <- getInts
      return (a, b)
    let intersections =
          map (\(i: _) -> (numerator i, denominator i)) $ group $ sort
            [ abs $ b % a
            | (a1, b1) <- points
            , (a2, b2) <- points
            , let a = a1 - a2
            , let b = b2 - b1
            , signum a * signum b == 1
            ]
        ans = listToMaybe $ sort
          [ minimumPair lo hi
          | (lo@(x1, y1), hi@(x2, y2)) <-
              ((0, 1): intersections) `zip` (intersections ++ [(1, 0)])
          , let x = x1 + x2
          , let y = y1 + y2
          , let order = map snd $
                  sort [(a * x + b * y, i) | ((a, b), i) <- points `zip` [0 ..]]
          , order == [0 .. n - 1]
          ]
    printf "Case #%d: " ri
    case ans of
      Just (ansx, ansy) -> printf "%d %d\n" ansx ansy
      Nothing -> putStrLn "IMPOSSIBLE"
  where
  readInt s = let Just (i, _) = C.readInt s in i
  getInts = map readInt . C.words <$> C.getLine
