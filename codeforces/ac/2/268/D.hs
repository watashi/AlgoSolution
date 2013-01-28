{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Data.Array.Unboxed

type State = (Bool, Int, Int, Int)

(+%) :: Int -> Int -> Int
a +% b = if c >= m then c - m else c
  where
    c = a + b
    m = 1000000009

gao :: Int -> Int -> UArray State Int
gao h n = go n $ newArray [((True, 0, 0, 0), 4)]
  where
    newArray = accumArray (+%) 0 ((False, 0, 0, 0), (True, h, h, h))
    state = [(f, i, j, k) |
      f <- [False, True], i <- [0 .. h], j <- [i .. h], k <- [j .. h]] -- !important
    go 1 dp = dp
    go m dp = go (m - 1) $ newArray $ concat [next i $ dp!i | i <- state]
      where
        next (f, i, j, k) e
          | f         = [
              ((i < h, 0, j', k'), e),
              ((j < h, 0, i', k'), e),
              ((k < h, 0, i', j'), e),
              ((True, i', j', k'), e)]
          | otherwise = [
              ((i < h, j', k', h), e),
              ((j < h, i', k', h), e),
              ((k < h, i', j', h), e),
              ((False, i', j', k'), e)]
          where
            [i', j', k'] = map (min h . succ) [i, j, k]

main :: IO ()
main = do
  [n, h] <- fmap (map read . words) getLine
  let h' = h - 1
      ans = gao h' n
  print $ foldl1 (+%) [e | ((f, i, _, _), e) <- assocs ans, f || i < h']
