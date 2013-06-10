{-
(x-y)+(y-z)=(x-z)
(x-y)+(y+z)=(x+z)
-}
import Control.Arrow
import Data.Array
import Data.List
import Data.Ord
import NumberTheory

limit = 1000

isSquare n = (floor $ sqrt $ fromIntegral n) ^ 2 == n

todo = assocs $
  accumArray (flip (:)) [] (0, limit) $
  concatMap (\(i, j, k) -> [(i, (j, k)), (j, (i, k))]) $
  pythagoreanTriples limit

solutions = [[x, y, z] |
  (a, list) <- map ((^2) *** (map ((^2) *** (^2)))) todo,
  (b, c) <- list,
  (d, e) <- list,
  b < d,
  even $ e - c,
  z <- [div (e - c) 2],
  (x, y) <- [(a + b + z, b + z)],
  isSquare $ x + y]

main = print $ maximum $ map sum $ solutions
