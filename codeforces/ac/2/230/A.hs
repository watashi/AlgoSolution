import Control.Monad
import Data.List

getArray = fmap (map read . words) getLine

main = do
  [s, n] <- getArray
  a <- replicateM n getArray
  putStrLn $ (\i -> if i > 0 then "YES" else "NO") $ foldl (\z [x, y] -> if z > x then z + y else 0) s $ sort a
