{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
module ProjectEuler.NumberTheory.Powers (
  isqrt
  ) where

-- | The 'isqrt' function returns the integer square root of given integer.
isqrt :: Integral a => a -> a
isqrt n
  | n > 0     = newton n
  | n == 0    = 0
  | otherwise = undefined
  where
    f x = (x + n `quot` x) `quot` 2
    newton x = let x' = f x in if x' < x then newton x' else x
