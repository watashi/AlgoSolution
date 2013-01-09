{-# OPTIONS -O2 -optc-O3 #-}
module ContinuedFraction (
  fromList,
  toList,
  truncate,
  convergents,
  sqrt,

  solvePell,
  solveNegPell,
  ) where

import Prelude hiding (truncate, sqrt)
import Data.Ratio
import NumberTheory (isqrt)

data CF a
  = CF [a]
  deriving (Eq, Show)

fromList a = CF a

toList (CF a) = a

truncate n (CF a) = CF (take n a)

convergents :: (Integral a, Fractional b) => CF a -> [b]
convergents (CF a) = drop 1 $ zipWith (/) nums dens
  where
    (h: t) = a
    f h = map (fromIntegral . fst) . scanl (\(a, b) d -> (d * a + b, a)) h
    nums = f (h, 1) t
    dens = f (1, 0) t

------------------------------------------------------------------------
--

-- sqrt
sqrt :: (Integral a) => a -> CF a
sqrt n = CF $ if m ^ 2 == n then [m] else f' (0, 1)
  where
    m = isqrt n
    f' (a, b) = d: f' (a', b')
      where
        d = div (m + a) b
        a' = d * b - a
        b' = div (n - a' ^ 2) b

-- solvePell
-- x^2 - n*y^2 = 1
solvePell :: Integral a => a -> [(a, a)]
solvePell n = [(x, y) |
  (x, y) <- map (\i -> (numerator i, denominator i)) $ convergents $ sqrt n,
  x ^ 2 - n * y ^ 2 == 1]

-- solveNegPell
-- x^2 - n*y^2 = -1
-- (x^2 + n*y^2)^2 - n(2xy)^2 = 1
-- (2x^2 + 1)^2 - n(2xy)^2 = 1
solveNegPell n = [(x, y) |
  (u, v) <- solvePell n,
  x <- [isqrt $ (u - 1) `div` 2],
  2 * x ^ 2 + 1 == u,
  y <- [div v $ 2 * x],
  2 * x * y == v]
