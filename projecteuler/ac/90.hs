import Data.List

choose _ 0     = [[]]
choose [] _    = []
choose (h:t) n = choose t n ++ [h:i | i <- choose t (n - 1)]

arrangements = map extend $ choose [0 .. 9] 6
  where
    extend a = if elem 6 a || elem 9 a then nub $ 6:9:a else a

ok a b = foldl1 (&&) [(elem i a && elem j b) || (elem i b && elem j a) | (i, j) <- squares]
  where
    squares = map ((`divMod` 10) . (^ 2)) [1 .. 9]

main = do
  print $ sum $ [1 | (i:t) <- init $ tails arrangements, j <- t, ok i j]
