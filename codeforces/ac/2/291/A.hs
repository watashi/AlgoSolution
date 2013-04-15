import Control.Applicative
import Data.List

main :: IO ()
main = do
  _ <- getLine
  a <- map length . group . sort . filter (/=(0::Int)) . map read . words <$> getLine
  print $ if maximum (0:a) > 2 then -1 else length $ filter (==2) a
