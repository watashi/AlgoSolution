{-
n*(n-1) = 2m*(m-1), find min n > 10^12
n^2 - 2*m^2 = n-2m
(n-1/2)^2 - 1/4 = 2((m-1/2)^2 - 1/4)
(n-1/2)^2 - 2(m-1/2)^2 = -1/4
(2n-1)^2 - 2(2m-1)^2 = -1
x^2 - 2y^2 = -1
x^4 - 4x^2y^2 + 4y^4 = 1
(x^2 + 2y^2)^2 - 2(2xy)^2 = 1
(2x^2 + 1)^2 - 2(2xy)^2 = 1
= http://oeis.org/A011900
-}

import Control.Arrow
import Data.List
import Data.Maybe
import Data.Ratio

-- main = do putStrLn $ show $ [(m, n) | m <- [1 .. ], x <- [m * pred m], n <- [ceiling $ sqrt $ fromIntegral $ 2 * x], y <- [n * pred n], y == 2 * x]

isqrt = floor . sqrt . fromIntegral

-- http://en.wikipedia.org/wiki/Continued_fraction
-- http://en.wikipedia.org/wiki/Periodic_continued_fraction
contFracOfSqrt :: Integer -> [Integer]
contFracOfSqrt n = if m ^ 2 == n then [m] else f' (0, 1)
  where
    m = isqrt n
    f' (a, b) = d: f' (a', b')
      where
        d = div (m + a) b
        a' = d * b - a
        b' = div (n - a' ^ 2) b

convergence :: [Integer] -> [Rational]
convergence = map (foldr1 (\i j -> i + (1%1)/j)) . tail . inits . map fromIntegral

solutions = [(div (x + 1) 2, div (y + 1) 2) |
  i <- convergence $ contFracOfSqrt $ 2,
  (n, d) <- [(numerator &&& denominator) i],
  n ^ 2 - 2 * d ^ 2 == 1,
  x <- [isqrt $ div (n - 1) 2],
  odd x && 2 * x ^ 2 + 1 == n,
  y <- [div d $ 2 * x],
  odd y && 2 * x * y == d]

main = do
  print $ span ((<=10^12) . fst) $ solutions

-- http://en.wikipedia.org/wiki/Pell%27s_equation

