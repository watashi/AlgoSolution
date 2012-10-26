{-
n^2 - m^2 = t
(n-m)(n+m) = t
2|n-m
2|n+m
4|t
floor(d(t/4)/2)
-}

import Data.IntMap (fromListWith, assocs)
import Primes

divisorNumber = product . map (succ . snd) . primeDivision

tileNumber n
  | m == 0    = divisorNumber d `div` 2
  | otherwise = 0
  where
    (d, m) = divMod n 4

ans = fromListWith (+) [(k, 1) | i <- [1 .. 1000000], k <- [tileNumber i], k > 0]

main = print $ sum $ map snd $ filter ((<=10) . fst) $ assocs $ ans
