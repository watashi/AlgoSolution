import Control.Monad
import Data.List
import Data.Maybe

main :: IO ()
main = do
  a <- replicateM 5 $ fmap (elemIndex (1::Int) . map read . words) getLine
  let i = fromJust $ findIndex isJust a
      j = fromJust $ a!!i
  print $ abs (i - 2) + abs (j - 2)
