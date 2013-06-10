import Data.List

(//) a (i, e) = take i a ++ [e] ++ drop (succ i) a

sz = 5

link i = [i + sz, i, mod (succ i) sz]

linksum a i = let b = map (a!!) $ link i in if elem 0 b then 0 else sum b

valid a = (<=1) $ length $ group $ filter (>0) $ [linksum a i | i <- [0 .. pred sz]]

normarlize a = minimum $ take sz $ iterate rotate b
  where
    b = [map (a!!) $ link i | i <- [0 .. pred sz]]
    rotate (h:t) = t ++ [h]

gao a [] = [normarlize a]
gao a (h:t) = concat [gao b t | i <- elemIndices 0 a, b <- [a // (i, h)], valid b]

main = do
  print $ concat $ map show $ concat $ maximum $ gao ((replicate 10 0) // (sz, 2 * sz)) [1..9]
