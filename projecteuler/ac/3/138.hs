{-
h = r^2 - s^2
b = 2 * 2rs = 4rs
r^2 - s^2 - 4rs = (r-2s)^2 - 5s^2 = \pm 1
-}

import Data.Ratio
import Enumeration (merge)
import ContinuedFraction (solvePell, solveNegPell)

solutions = [(r ^ 2 - s ^ 2, 4 * r * s, r ^ 2 + s ^ 2) |
  (r, s) <- map (\(i, j) -> (i + 2 * j, j)) $ merge (solvePell 5) (solveNegPell 5)]

main = print $ sum $ map (\(i, j, k) -> k) $ take 12 solutions
