import Data.List
import Data.Ord

main :: IO ()
main = do
  [n, m] <- fmap (map read . words) getLine
  let f i = (abs $ 1 + m - 2 * i, i)
  putStr $ unlines $ map show $ take n $ cycle $ sortBy (comparing f) $ [1 .. m]
