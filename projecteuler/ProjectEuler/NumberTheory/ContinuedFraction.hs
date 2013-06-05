{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
module ProjectEuler.NumberTheory.ContinuedFraction (
  fromList,
  toList,

  convergents,

  sqrt,

  solvePell,
  solveNegPell,
  ) where

import Prelude hiding (sqrt)

import ProjectEuler.NumberTheory.Power (isqrt)

import Control.Applicative (liftA2)
import Data.Ratio (numerator, denominator)

data ContinuedFraction a
  = CF [a]
  deriving (Show)

fromList :: [a] -> ContinuedFraction a
fromList a = CF a

toList :: ContinuedFraction a -> [a]
toList (CF a) = a

convergents :: (Integral a, Fractional b) => ContinuedFraction a -> [b]
convergents (CF []) = [0]
convergents (CF (h:t)) = drop 1 $ zipWith (/) nums dens
  where
    f x = map (fromIntegral . fst) . scanl g x
    g (i, j) k = (k * i + j, i)
    nums = f (h, 1) t
    dens = f (1, 0) t

-- sqrt
sqrt :: (Integral a) => a -> ContinuedFraction a
sqrt n = CF $ if m * m == n then [m] else go (0, 1) 
  where
    m = isqrt n
    go (a, b) = d: go (a', b')
      where
        d = (m + a) `quot` b
        a' = d * b - a
        b' = (n - a' * a') `quot` b

-- solvePell
-- x^2 - n*y^2 = 1
solvePell :: Integral a => a -> [(a, a)]
solvePell n = [(x, y) |
  (x, y) <- map (liftA2 (,) numerator denominator) $ convergents $ sqrt n,
  x * x - n * y * y == 1]

-- solveNegPell
-- x^2 - n*y^2 = -1
-- (x^2 + n*y^2)^2 - n(2xy)^2 = 1
-- (2x^2 + 1)^2 - n(2xy)^2 = 1
solveNegPell :: Integral a => a -> [(a, a)]
solveNegPell n = [(x, y) |
  (u, v) <- solvePell n,
  let x = isqrt $ pred u `quot` 2,
  2 * x * x + 1 == u,
  let y = v `quot` (2 * x),
  2 * x * y == v]
