import Control.Monad
import Data.Bits
import Data.List
import System.IO

limit :: Int
limit = 10 ^ 9

main :: IO ()
main = do
  hSetBuffering stdout LineBuffering
  re <- readLn
  replicateM_ re $ do
    n <- readLn
    let
      bin = takeWhile (<=limit) (iterate (*2) 1)
      a = take n $ nub $ bin <> iterate pred limit
    putStrLn $ unwords $ map show a
    b <- map read . words <$> getLine
    let
      c = a <> b
      go r x
        | r <= limit = filter (\i -> r .&. i /= 0) bin
        | otherwise = let (h: t) = x in h: go (r - h) t
      ans = go (sum c `quot` 2) (c \\ bin)
    putStrLn $ unwords $ map show ans
