import Data.List
import Enumeration

solve n = filter (\(i, j) -> not $ trivial i j) pairs
  where
    a = combinations (div n 2) [1 .. n]
    trivial x y = foldr1 (&&) $ zipWith (<=) x y
    pairs = [(i, j) |
      m <- [2 .. div n 2],
      (i:t) <- init $ tails $ combinations m [1 .. n],
      j <- t,
      null $ intersect i j]

main = print $ length $ solve 12
