import Primes
import Data.Array
import Data.List

maxn = 10000000
primeList = primesToN maxn
primeArray = accumArray (curry snd) False (0, maxn) $ zip primeList $ repeat True
isPrime n
  | n < maxn  = primeArray ! n
  | otherwise = foldr1 (&&) [mod n i /= 0 | i <- takeWhile (\i -> i * i < n) primeList]

merge x = concatMap gao $ groupBy (\i j -> init i == init j) x
  where
    ok i j = isPrime $ read $ (show i) ++ (show j)
    gao y = map (h++) [[i, j] | (i:k) <- t, j <- k, ok i j && ok j i]
      where
        h = init $ head y
        t = init $ tails $ map last y

main = do
  print $ (!!4) $ iterate merge $ map (:[]) $ primesToN 10000

{-
15.06s user 0.41s system 38% cpu 39.904 total
-}
