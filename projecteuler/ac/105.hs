import Data.List
import System.IO

sums [] = [0]
sums (h:t) = concat [[i, i + h] | i <- sums t]

good x = rule2 x && rule1 x
  where
    rule1 a = all (null . tail) $ group $ sort $ sums a
    rule2 a = let b = sort a in all id $ zipWith (<) (scanl1 (+) $ 0:reverse b) $ scanl1 (+) $ b

main = do
  handle <- openFile "105sets.txt" ReadMode
  hSetNewlineMode handle $ NewlineMode CRLF LF
  input <- hGetContents handle
  print $ sum [sum set | line <- lines input, set <- [read $ "[" ++ line ++ "]"], good set]
