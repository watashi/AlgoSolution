import Data.Array

main = do
  [n, m, s] <- fmap (map read . words) getLine
  print $ solve n m s

solve n m s = sum $ rect ++ cross
  where
    a = accumArray (flip (:)) [] (0, n * m) $
      [(i * j, (i, j)) | i <- [1, 3 .. n], j <- [1, 3 .. m]]
    ord x = succ x `div` 2
    count r c = (n + 1 - r) * (m + 1 - c)
    rect = [count r c * (k + k - 1)  | (r, c) <- a!s, let k = ord r * ord c]
    cross = [count r c * 2 |
        u <- [1 .. div n 2],
        v <- [1 .. div m 2],
        let t = s + 4 * u * v,
        t <= n * m,
        (r, c) <- a!t,
        2 * u < r && 2 * v < c]
