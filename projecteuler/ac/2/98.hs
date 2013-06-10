import Data.List
import Data.Maybe
import Data.Ord
import System.IO
import qualified Data.Map as M

normalize :: Ord k => [k] -> [Int]
normalize str = normalize' str M.empty
  where
    normalize' [] d = []
    normalize' s@(h:t) d
      | M.notMember h d = normalize' s $ M.insert h (M.size d) d
      | otherwise       = fromJust (M.lookup h d): normalize' t d

anagrams :: [String] -> [[String]]
anagrams list = M.elems $ M.fromListWith (++) [(sort i, [i]) | i <- list]

gao a b = [(a, i, b, j) |
    i <- candidates a,
    j <- candidates b,
    check $ zip a i ++ zip b j]
  where
    n = length a
    check d = length (nub d) == length (nub $ map fst d)
    squares = map show $ takeWhile (< 10 ^ n) $ dropWhile (< 10 ^ pred n) [i ^ 2 | i <- [1 ..]]
    candidates x = [i | y <- [normalize x], i <- squares, y == normalize i]

cmp (a, i, b, j) = (read :: String -> Int) $ max i j

main = do
  handle <- openFile "98words.txt" ReadMode
  list <- fmap (\i -> read $ "[" ++ i ++ "]") $ hGetContents handle
  print $ sortBy (comparing cmp) $ concat $ [gao i j | a <- anagrams list, i <- a, j <- a, i < j]

{-
./98  0.57s user 0.01s system 58% cpu 0.993 total
-}
