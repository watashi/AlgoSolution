import Control.Monad
import Data.Char
import Data.Function
import Data.List
import Text.Printf

gao :: [String] -> (Int, Int)
gao xs = (m, n - m)
  where
  n = length xs
  m = sum
    [ x + (if y >= 2 then 2 else 0)
    | i <- groupBy ((==) `on` head) $ filter (not . null) xs
    , let (x, y) = gao $ map tail i
    ]

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    n <- readLn
    s <- replicateM n $
      reverse . filter isAsciiUpper <$> getLine
    printf "Case #%d: %d\n" ri $ fst $ gao $ sort s
