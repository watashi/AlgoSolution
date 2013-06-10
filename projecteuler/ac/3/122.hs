import Data.Array
import Data.List

{-
limit = 200

gen 0 a = [(head a, length a)]
gen n a@(h:_) = (head a, length a): concat [gen (n-1) $ i:a | i <- s]
  where
    s = map head $ group $ sort $ [k | i <- a, j <- a, i <= j, k <- [i + j], h < k, k <= limit]

main = print $ sum $ map pred $ elems $ accumArray min 11 (1, limit) $ gen 9 [1]

-- 1581
-}

gao n = go [1] 16
  where
    go a@(h:t) m
      | h == n          = min m u
      | last greed == n = min m (v-1)
      | v >= m          = m
      | otherwise       = foldl (\i j -> go (j:a) i) m b
      where
        greed = takeWhile (<=n) $ iterate (*2) h
        u = length a
        v = u + length greed
        b = map head $ group $ reverse $ sort $
          [k | i <- a, j <- a, i <= j, k <- [i + j], h < k, k <= n]

main = print $ sum $ map (pred . gao) [1 .. 200]

-- ./122  3.06s user 0.03s system 73% cpu 4.208 total

