import Data.Array
import Data.Char (digitToInt)
import Data.List
import Data.Ord (comparing)
import System.IO

parse input = listArray ((0,0), (8,8)) $ map digitToInt $ concatMap (take 9) $ tail input

solve initSudoku = gao initSudoku initCandidates
  where
    fill candidates (x, y) z = accum (flip delete) candidates [(i, z) | i <- row ++ col ++ box]
      where
        row = zip (repeat x) [0 .. 8]
        col = zip [0 .. 8] (repeat y)
        box = [(i, j) | i <- range x, j <- range y]
        range i = take 3 [div i 3 * 3 ..]
    initCandidates = foldl (\i (p, q) -> fill i p q) fullCandidates initCells
      where
        initCells = filter ((/=0) . snd) $ assocs initSudoku
        fullCandidates = listArray ((0,0), (8,8)) $ repeat [1 .. 9]
    gao sudoku candidates
      | null blanks = [sudoku]
      | otherwise   = concat [gao (sudoku//[(todo,i)]) (fill candidates todo i) | i <- candidates!todo]
      where
        blanks = filter ((==0) . (sudoku!)) $ indices sudoku
        todo = minimumBy (comparing (length . (candidates!))) blanks

main = do
  handle <- openFile "96sudoku.txt" ReadMode
  grids <- fmap (takeWhile (not . null) . iterate (drop 10) . lines) $ hGetContents handle
  print $ sum $ map (score . head . solve . parse) grids
  where
    score = foldl1 (\i j -> i * 10 + j) . take 3 . elems
