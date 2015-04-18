import Control.Monad
import Data.Int
import Text.Printf

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    (_:n:_) <- map read . words <$> getLine
    a <- map read . words <$> getLine
    let finished t = sum [(t + i - 1) `quot` i | i <- a]
        go lo hi
          | lo == hi = lo
          | finished mi < n = go (mi+1) hi
          | otherwise = go lo mi
          where
          mi = (lo + hi) `quot` (2 :: Int64)
        time = go 0 (n * minimum a) - 1
        available = [i | (i, j) <- zip [1::Int ..] a, time `rem` j == 0]
        ans = available !! fromIntegral (n - finished time - 1)
    printf "Case #%d: %d\n" ri ans
