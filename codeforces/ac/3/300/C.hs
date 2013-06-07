{-# LANGUAGE GeneralizedNewtypeDeriving #-}
import Control.DeepSeq
import Data.Array
import Data.Int

newtype MInt
  = MInt Int64
  deriving (Enum, Eq, NFData)

m :: Int64
m = 1000000007

factCache :: Array Int MInt
factCache = let n = 1000000 in listArray (0, n) $ force $ scanl (*) 1 [1 .. fromIntegral n]

fact :: Int -> MInt
fact i = factCache!i

modInv :: MInt -> MInt
modInv a = a ^ (m - 2)

instance Show MInt where
  show (MInt a) = show a

instance Num MInt where
  (+) (MInt a) (MInt b) = let c = a + b in MInt $ if c >= m then c - m else c
  (*) (MInt a) (MInt b) = MInt $ a * b `mod` m
  abs = id
  signum (MInt a) = if a == 0 then 0 else 1
  fromInteger a = MInt $ fromInteger $ a `mod` toInteger m

choose :: Int -> Int -> MInt
choose n k = fact n * modInv (fact k) * modInv (fact $ n - k)

gao :: Int -> Int -> Int -> Int -> MInt
gao n a b c =
  if x >= 0 && y >= 0 && xr == 0 && yr == 0
    then choose (x + y) $ min x y
    else MInt 0
  where
    (x, xr) = divMod (b * n - c) (b - a)
    (y, yr) = divMod (c - a * n) (b - a)

main :: IO ()
main = do
  [a, b, n] <- fmap (map read . words) getLine
  let c = concat $ take 7 $ iterate (\i -> concatMap (\j -> [j * 10 + a, j * 10 + b]) i) [a, b]
      ans = sum $ map (gao n a b) c
  print ans
