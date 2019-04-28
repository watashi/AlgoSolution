import Control.Monad
import Data.List

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- read <$> getLine
    a <- replicateM (2 * n - 1) $ map read . words <$> getLine
    let ans = [head i | i <- group $ sort $ concat a, odd $ length i] :: [Int]
    putStrLn $ "Case #" ++ show ri ++ ": " ++ unwords (map show ans)
