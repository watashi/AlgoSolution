import Control.Monad
import Data.List

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    n <- readLn
    a <- replicateM n $ fmap (read . head . words) getLine :: IO [Int]
    putStrLn $ if length a == length (nub a) then "YES" else "NO"