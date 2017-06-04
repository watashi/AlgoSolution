import Control.Applicative
import Data.List

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f lo hi = go lo hi
  where
  go l h
    | l == h = h
    | f m = go l m
    | otherwise = go (m+1) h
    where
    m = l + (h - l) `quot` 2

main :: IO ()
main = do
  let getInts = map read . words <$> getLine
  (n:m:_) <- getInts
  a <- zip <$> getInts <*> getInts
  let cost k = sum $ take k $ sort [i + (k - 1) * j | (i, j) <- a]
      ans =  bsearch ((>m) . cost) 0 (n+1) - 1
  print $ bsearch ((>m) . cost) 0 (n+1) - 1