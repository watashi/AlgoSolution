{-# LANGUAGE DataKinds #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}

import Control.Applicative
import Data.Array
import Data.List
import GHC.TypeLits

newtype MIntT i (n :: Nat) = MInt i
  deriving (Enum, Eq, Ix, Ord)

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

type MInt = MIntT Int 101

gao :: [MInt] -> Maybe String
gao [] = Nothing
gao (h: t) = case foldl' gen (buildA [(h, "")]) t ! 0 of
  Just o -> Just $ concat $ show h: zipWith (\i j -> i: show j) (reverse o) t
  Nothing -> Nothing
  where
  buildA = accumArray (\_ i -> Just i) Nothing (0, -1)
  gen a x = buildA $
    [ (i `f` x, g: e)
    | (i, Just e) <- assocs a
    , (f, g) <- [((+), '+'), ((-), '-'), ((*), '*')]
    ]

main :: IO ()
main = do
  _ <- getLine
  a <- map (mint . read) . words <$> getLine
  case gao a of
    Just ans -> putStrLn ans
    Nothing -> undefined