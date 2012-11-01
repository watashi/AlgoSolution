import Control.Monad
import Data.List
import Data.Array

solve n m a = d!(n-1)
  where
    ix = (0, n + m - 1)
    e = accumArray (flip (:)) [] ix $ concat
      [[(i, n + j), (n + j, i)] | (i, b) <- zip [0 ..] a, (j, c) <- zip [0 ..] b, c == '#']
    d = snd $ until (null . snd . fst) bfs ((0, [0]), accumArray (+) (-1) ix [(0, 1)])
    bfs ((u, v), d) = ((u', v'), d // zip v' (repeat u'))
      where
        u' = succ u
        v' = map fst $ filter snd $ assocs $ accumArray (||) False ix [(j, True) | i <- v, j <- e!i, d!j == -1]

main = do
  [n,m] <- fmap (map read . words) getLine
  a <- replicateM n getLine
  print $ solve n m a
