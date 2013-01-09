{-# OPTIONS -O2 -optc-O3 #-}
module NumberTheory (
  isqrt,

  powMod,
  extGcd,
  modInv,

  eulerTotient,

  pythagoreanTriples,
  primitivePythagoreanTriples
  ) where

import Control.Arrow (second)
import Primes (primeDivision)

isqrt :: (Integral a, Integral b) => a -> b
isqrt = floor . sqrt . fromIntegral

------------------------------------------------------------------------
-- Fundamentals

divides :: Integral a => a -> a -> Bool
m `divides` n = mod n m == 0

-- idecomposite
-- (m, r) == idecomposite n p <=> n == p ^ r * m && gcd m p == 1
idecomposition :: (Integral a, Integral b) => a -> a -> (a, b)
idecomposition n p
  | m /= 0    = (n, 0)
  | otherwise = second succ $ idecomposition d p
  where
    (d, m) = divMod n p

isignificand :: Integral a => a -> a -> a
isignificand n = fst . idecomposition n

iexponent :: (Integral a, Integral b) => a -> a -> b
iexponent n = snd . idecomposition n

-- powMod
-- powMod a b m = mod (a^b) m
-- > powMod 2 1000 (10^9+7) = 688423210
powMod :: (Integral a, Integral b) => a -> b -> a -> a
powMod a b m = powMod' b
  where
    powMod' b
      | b == 0    = mod 1 m
      | odd b     = mod (powMod' (b - 1) * a) m
      | otherwise = mod (powMod' (div b 2) ^ 2) m

-- extGcd
-- > extGcd 7 10 = (1, (3, -2))
extGcd :: Integral a => a -> a -> (a, (a, a))
extGcd a b
  | a >= 0 && b >= 0  = extGcd' a b

extGcd' a 0 = (a, (1, 0))
extGcd' a b = (g, (y, x - d * y))
  where
    (g, (x, y)) = extGcd' b m
    (d, m) = divMod a b

-- modInv
-- > modInv 7 10 = 5
-- > 5 * 10 `mod` 7 = 1
modInv :: Integral a => a -> a -> a
modInv m n
  | g == 1  = mod y m
  where
    (g, (x, y)) = extGcd' m n

------------------------------------------------------------------------
-- Arithmetic Functions

-- eulerTotient
-- http://en.wikipedia.org/wiki/Euler%27s_totient_function
eulerTotient :: Integral a => a -> a
eulerTotient n = foldl (\m p -> div m p * pred p) n $ map fst $ primeDivision n

------------------------------------------------------------------------
--

-- pythagoreanTriples
-- http://en.wikipedia.org/wiki/Pythagorean_triple
pythagoreanTriples :: Integral a => a -> [(a, a, a)]
pythagoreanTriples n = concatMap expand $ primitivePythagoreanTriples n
  where
    expand (x, y, z) = takeWhile (\(_, _, i) -> i <= n) [(i*x, i*y, i*z) | i <- [1 ..]]

primitivePythagoreanTriples :: Integral a => a -> [(a, a, a)]
primitivePythagoreanTriples n = [(min x y, max x y, z) |
  r <- [1 .. isqrt n],
  s <- [1 .. min (r - 1) $ isqrt $ n - r ^ 2],
  odd (r + s),
  gcd r s == 1,
  (x, y, z) <- [(r ^ 2 - s ^ 2, 2 * r * s, r ^ 2 + s ^ 2)]]

