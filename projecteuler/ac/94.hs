{-
== (2x,2x+1,2x+1)
(2x+1)^2-x^2=3x^2+4x+1=(3x+1)(x+1)=y^2
gcd(3x+1,x+1)=gcd(x+1,2)
=== even x
3x+1=u^2, x+1=v^2
=== odd x
3x+1=u^2, x+1=v^2
2(3x+1)=u^2, x+1=2*v^2
3x+1=2*u^2, 2(x+1)=v^2

== (2x,2x-1,2x-1)
(3x-1)(x-1)=y^2
-}

import Data.List

limit = 10 ^ 9

squares = takeWhile (<=limit) [i^2 | i <- [1..]]

isqrt = floor . sqrt . fromIntegral

isSquare n = (isqrt n) ^ 2 == n

triangle = map head $ group $ sort $ [[2 * x, 2 * x - j, 2 * x - j] |
  i <- squares,
  j <- [1, -1],
  x <- map (+j) [i, 2 * i, div i 2],
  1 < x && x <= limit,
  isSquare $ (2 * x - j) ^ 2 - x ^ 2]

main = do
  print $ sum $ filter (<=limit) $ map sum triangle
