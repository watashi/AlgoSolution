import Control.Monad
import Data.List

main :: IO ()
main = do
  n <- fmap read getLine
  a <- replicateM n $ fmap (map read . words) getLine :: IO [[Int]]
  print $ length [True | i <- a, j <- delete i a, head i == last j]

