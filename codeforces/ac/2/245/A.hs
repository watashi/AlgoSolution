import Control.Monad (replicateM)
import Data.List (transpose)

gao a = if n >= d then "LIVE" else "DEAD"
  where
    (n:d:_) = map sum $ transpose $ map (map read . tail) a

main = do
  n <- fmap read getLine
  a <- replicateM n $ fmap words getLine
  putStrLn $ gao $ filter ((=="1") . head) a
  putStrLn $ gao $ filter ((=="2") . head) a
