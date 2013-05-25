import qualified Data.Map as M
import ProjectEuler.ListUtils
import Text.Printf

main :: IO ()
main = do
  let seed = M.singleton [1, 0, 0, 0, 0] 1.0 :: M.Map [Int] Double
      x = takeWhile (not . M.null) $
        iterate (M.fromListWith (+) . concatMap gao . M.assocs) seed
      y = [sum [v | (k, v) <- M.assocs i, sum k == 1] | i <- x]
      gao (k, v)
        | s <= 0    = []
        | otherwise = [(k', v') |
          (i, e) <- zip [0..] k, e > 0,
          let k' = k `replaceWith` zip [i..n-1] (pred: repeat succ),
          let v' = v * fromIntegral e / fromIntegral s]
        where
          n = length k
          s = sum k
  print $ head x
  print $ last x
  print $ sum y
  printf "%.6f\n" $ sum y - 2
