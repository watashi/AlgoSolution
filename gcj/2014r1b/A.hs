import Control.Applicative
import Control.Monad
import Data.List
import Data.Function

gao :: [Int] -> Int
gao a = sum [abs $ i - m | i <- a]
  where
  m = sort a !! (length a `quot` 2)

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- read <$> getLine
    a <- replicateM n $ group <$> getLine
    putStr $ "Case #" ++ show ri ++ ": "
    if length (groupBy ((==) `on` map head) a) > 1
      then putStrLn "Fegla Won"
      else print $ sum [gao $ map length i | i <- transpose a]
