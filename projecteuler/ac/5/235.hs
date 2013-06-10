import Enumeration

degree = 5000 - 1

y = -6.0e11 :: Double

function x = foldr1 (\i j -> j * x + i) [(897 - 3 * i) | i <- [0 .. degree]]

den = 10 ^ 24 :: Integer

num = binarySearch' (\i -> function (fromInteger i / fromInteger den) <= y) 0 $ den + den

main = print $ fromInteger num / fromInteger den
