{-# LANGUAGE DataKinds #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}

import Data.List
import GHC.TypeLits

newtype MIntT i (n :: Nat) = MInt i
  deriving (Enum, Eq)

instance Show i => Show (MIntT i n) where
  show (MInt a) = show a

modulo :: (KnownNat n, Num i) => MIntT i n -> i
modulo = fromInteger . natVal

mint :: (KnownNat n, Integral i) => i -> MIntT i n
mint a = let m = MInt $ a `mod` modulo m in m

instance (KnownNat n, Integral i) => Num (MIntT i n) where
  (+) m@(MInt a) (MInt b) =
    let c = a + b in MInt $ if c >= modulo m then c - modulo m else c
  (-) m@(MInt a) (MInt b) =
    let c = a - b in MInt $ if c >= 0 then c else c + modulo m
  (*) m@(MInt a) (MInt b) = MInt $ a * b `rem` modulo m
  abs = error "abs"
  negate m@(MInt a) = if a == 0 then 0 else MInt $ modulo m - a
  signum = error "signum"
  fromInteger a = let m = MInt $ fromInteger (a `mod` natVal m) in m

type MInt = MIntT Int 1000000007

dp :: [[[MInt]]]
dp = iterate gen dp0
  where
  dp0 = (0: repeat 1): repeat (repeat 0)
  gen right = map (scanl (+) 0) $ transpose right
  
main :: IO ()
main = do
  re <- readLn
  sequence_ . replicate re $ do
    (n:m:k:_) <- fmap (map read . words) getLine
    let x = pred n
        y = pred m
        ans
          | x == 0 && y == 0 = 1
          | otherwise = sum [dpi!!x!!y + dpi!!y!!x | dpi <- take (k + 1) dp]
    print ans