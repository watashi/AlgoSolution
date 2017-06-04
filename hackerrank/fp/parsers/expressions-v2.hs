{-# LANGUAGE DataKinds #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}

import Control.Applicative hiding (many)
import Data.Char
import GHC.TypeLits
import Text.ParserCombinators.ReadP

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

inv :: MInt -> MInt
inv n = n ^ (modulo n - 2)

number, factor, term, expression :: ReadP MInt
number = mint . read <$> munch1 isDigit
factor =
      number
  <++ (char '+' *> factor)
  <++ (negate <$> (char '-' *> factor))
  <++ (char '(' *> expression <* char ')')
term = (*) <$> factor <*> (op <*> term) <++ pure 1
  where
  op = (char '*' *> pure id) <++ (char '/' *> pure inv)
expression = (+) <$> term <*> (op <*> expression) <++ pure 0
  where
  op = (char '+' *> pure id) <++ (char '-' *> pure negate)
  
main :: IO ()
main = do
  s <- filter (not . isSpace) <$> getLine
  let [(ans, "")] = readP_to_S (expression <* eof) s
  print ans