{-# LANGUAGE DataKinds #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}

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

type MInt = MIntT Int 100000007

choose :: [[MInt]]
choose = iterate (\i -> i `seq` zipWith (+) (0: i) (i ++ [0])) [1]

main :: IO ()
main = do
  re <- readLn
  sequence_ . replicate (choose!!1000 `seq` re) $ do
    (n:k:_) <- fmap (map read . words) getLine
    print $ choose!!n!!k