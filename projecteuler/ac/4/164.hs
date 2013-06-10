import Data.Array

sz = 10 ^ 3

ds 0 = 0
ds n = let (d, m) = divMod n 10 in m + ds d
dsTab = listArray (0, sz-1) [(i, ds i) | i <- [0 .. sz-1]]

gao n m = accumArray (+) 0 (0, sz-1) $ if n == 0 then [(0, 1)] else a
  where
    t = gao (n-1) m
    a = [(k, e) |
      (i, e) <- assocs $ gao (n-1) m,
      j <- [0 .. 9],
      k <- [mod (i * 10 + j) sz],
      ds k <= m]

main = print $ foldl1 (-) $ map (sum . elems . (flip gao) 9) [20, 19]
