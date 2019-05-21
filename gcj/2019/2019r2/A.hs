import Control.Monad
import qualified Data.ByteString.Char8 as C
import Data.Ratio
import Data.List
import Text.Printf

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
        ans = length intersections + 1
        {-
        orders = Set.fromList
          [ listArray (0, n - 1) $ map fromIntegral order :: UArray Int Word16
          | ((x1, y1), (x2, y2)) <-
              ((0, 1): intersections) `zip` (intersections ++ [(1, 0)])
          , let x = x1 + x2
          , let y = y1 + y2
          , let order = map snd $
                  sort [(a * x + b * y, i) | ((a, b), i) <- points `zip` [0 ..]]
          ]
        ans = Set.size orders
        -}
    printf "Case #%d: %d\n" ri ans
  where
  readInt s = let Just (i, _) = C.readInt s in i
  getInts = map readInt . C.words <$> C.getLine
