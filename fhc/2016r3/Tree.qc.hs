{-# LANGUAGE BangPatterns #-}

import Data.Bits
import Data.Monoid
import Data.Word (Word64)
import Text.Printf
import qualified Data.Map.Strict as Map
import Test.QuickCheck (quickCheck)

newtype Max a = Max { getMax :: a }
  deriving (Eq, Show)

instance (Bounded a, Ord a) => Monoid (Max a) where
  mempty = Max minBound
  Max a `mappend` Max b = Max $ max a b

data Tree a
  = Bin {-# UNPACK #-} !Word64    -- ^ Prefix
        {-# UNPACK #-} !Word64    -- ^ Mask
        !(Max a)                  -- ^ Aggregate value
        !(Tree a)                 -- ^ Left
        !(Tree a)                 -- ^ Right
  | Tip {-# UNPACK #-} !Word64    -- ^ Key
        !a                        -- ^ Value
  | Nil

instance (PrintfArg a, Show a) => Show (Tree a) where
  show (Bin prefix mask v l r) =
    printf "Bin %04b %04b (%d)\n%s%s" prefix mask (getMax v) (f l) (f r)
    where
    f = unlines . map ("  "++) . lines . show
  show (Tip k v) = printf "Tip %04b %d (%d)" k k v
  show Nil = "Nil"

getValue :: (Bounded a, Ord a) => Tree a -> Max a
getValue !root = case root of
  Bin _ _ value _ _ -> value
  Tip _ value -> Max value
  Nil -> mempty

prefixMask :: Word64 -> Word64 -> (Word64, Word64)
prefixMask !a !b = (prefix, mask)
  where
  prefix = a .&. b .&. (complement $ mask - 1)
  mask = (f 32 . f 16 . f 8 . f 4 . f 2 . f 1 $ a `xor` b) `unsafeShiftR` 1 + 1
  f !k !i = i .|. unsafeShiftR i k

-- a_k += 1
bump :: (Bounded a, Num a, Ord a) => Word64 -> Tree a -> Tree a
bump !k = go
  where
  go bin@(Bin prefix mask v l r)
    | k < prefix = Bin prefix' mask' (v <> Max 1) (Tip k 1) bin
    | k >= prefix + mask + mask = Bin prefix' mask' (v <> Max 1) bin (Tip k 1)
    | k .&. mask == 0 = let t = go l in Bin prefix mask (v <> getValue t) t r
    | otherwise = let t = go r in Bin prefix mask (v <> getValue t) l t
    where
    (prefix', mask') = prefixMask prefix k
  go tip@(Tip i v)
    | i < k = Bin prefix mask (Max v) tip (Tip k 1)
    | i > k = Bin prefix mask (Max v) (Tip k 1) tip
    | otherwise = Tip k $ v + 1
    where
    (prefix, mask) = prefixMask i k
  go Nil = Tip k 1

-- max_{i>=k}{a_i}
query :: (Bounded a, Num a, Ord a) => Word64 -> Tree a -> Max a
query !k = go
  where
  go (Bin prefix mask v l r)
    | k <= prefix = v
    | k >= prefix + mask + mask = mempty
    | k .&. mask == 0 = query k l <> getValue r
    | otherwise = query k r
  go (Tip i v)
    | i >= k = Max v
    | otherwise = mempty
  go Nil = mempty

test :: [Word64] -> [Word64] -> Bool
test x y =
  all (\i -> query i t == mconcat [Max v | (k, v) <- Map.toList m, k >= i]) y
  where
  t = foldr bump Nil x
  m = Map.fromListWith (+) $ x `zip` repeat (1 :: Int)

main :: IO ()
main = quickCheck test
