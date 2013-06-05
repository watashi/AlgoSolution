{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
module ProjectEuler.NumberTheory.Power (
  isqrt,
  icbrt,
  ) where

newton :: Integral a => (a -> a) -> a -> a
newton f x0 = go x0
  where
    go x = let x' = f x in if x' < x then go x' else x

-- | The 'isqrt' function returns the integer square root of given integer.
isqrt :: Integral a => a -> a
isqrt n
  | n > 0     = newton (\x -> (x + n `quot` x) `quot` 2) n
  | n == 0    = 0
  | otherwise = undefined

-- | The 'icbrt' function returns the integer cube root of given integer.
icbrt :: Integral a => a -> a
icbrt n
  | n > 0     = newton (\x -> (2 * x + n `quot` (x * x)) `quot` 3) n
  | n == 0    = 0
  | otherwise = let m = -icbrt(-n) in if m * m * m == n then m else pred m
  where
    
