import Control.Applicative
import Control.Monad
import Data.Array.Unboxed
import qualified Data.IntMap as Map
import Data.List

-- Assume:
--  A   B    C    D
-- _|   |_    _  _
--           |    |

solve :: (Int, Int, Int, [[Char]]) -> Int
solve (nrow, ncol, limit, grid) = total - maximum (elems dpn)
  where
  total = nrow * (ncol - 1) + ncol * (nrow - 1)
  dp0 = listArray (0, limit) $ repeat 0
  dpn = foldl' next dp0 $ rows ++ cols
  rows = map (gao $ \c -> c == 'A' || c == 'D') grid
  cols = map (gao $ \c -> c == 'A' || c == 'B') (transpose grid)

  next :: UArray Int Int -> [Int] -> UArray Int Int
  next pre cost = {-# SCC next #-} listArray (0, limit) $
    [ maximum [pre!(i-j) + k | (j, k) <- takeWhile ((<=i) . fst) cost']
    | i <- [0..limit]
    ]
    where
    -- constant optimization
    cost' = Map.toList $ Map.fromListWith max $ cost `zip` [0..]

gao :: (Char -> Bool) -> [Char] -> [Int]
gao _ [] = undefined
gao isLeft (x:xs) = {-# SCC gao #-} go xs (toLeft x [0]) (toRight x [0])
  where
  toLeft c = if isLeft c then id else map (+1)
  toRight c = if isLeft c then map (+1) else id
  go [] left right = zipWith min left right
  go (c:cs) left right = go cs (toLeft c left') (toRight c right')
    where
    left' = zipWith min (0: left) (right ++ [maxBound])
    right' = 0: zipWith min left right

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1 .. re] $ \ri -> do
    ans <- solve <$> getInput
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    (m:n:k:_) <- map read . words <$> getLine
    a <- replicateM m $ take n <$> getLine
    return (m, n, k, a)
