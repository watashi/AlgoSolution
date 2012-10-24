import Data.List

figurate n = takeWhile (<10000) $ dropWhile (<1000)
  [i * ((n - 2) * i - (n - 4)) `div` 2 | i <- [1 ..]]

isCyclic a b = mod a 100 == div b 100

gao x [] = [[x]]
gao x (h:t) = map (x:) $ concat [gao i t | i <- filter (isCyclic x) h]

main = do
  print $ map (\i -> (i, sum i)) $ filter varify candidates
  where
    varify candidate = isCyclic (last candidate) (head candidate)
    candidates = concat [gao i j | i <- figurate 3, j <- permutations $ map figurate [4 .. 8]]

