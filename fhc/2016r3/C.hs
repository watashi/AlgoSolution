{-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Arrow
import Control.Monad
import Control.Monad.Trans.State.Strict
import Data.Bits
import Data.Function
import Data.Int (Int64)
import Data.List
import Data.Maybe
import Data.Monoid
import Data.Word (Word64)
import qualified Data.ByteString.Char8 as C

newtype Max a = Max { getMax :: a }
  deriving (Show)

instance (Bounded a, Ord a) => Monoid (Max a) where
  mempty = Max minBound
  Max a `mappend` Max b = Max $ max a b

solve :: (Int, [(Int, Int)]) -> Int
solve (s0, p0) = gao p `max` gao p'
  where
  s = fromIntegral s0
  p = map (\i@((x,_):_) -> (x, map snd i)) $
    groupBy ((==) `on` fst) $ sort $ map (fromIntegral *** fromIntegral) p0
  p' = reverse $ map (first negate) p

  toWord64 :: Int64 -> Word64
  toWord64 = let offset = 2 ^ 60 in fromIntegral . (offset+)

  gao a = let ans = evalState go (Nil, Nil) in maximum ans
    where
    go = forM a $ \(x, ts) -> do
      from <- forM ts $ \t -> do
        let y = toWord64 $ x - s * t
        Max ret <- gets $ query y . fst
        modify $ first $ bump y
        return $ max ret 0
      to <- fmap reverse $ forM (reverse ts) $ \t -> do
        let y = toWord64 $ x + s * t
        Max ret <- gets $ query y . snd
        modify $ second $ bump y
        return $ max ret 0
      let from' = scanl1 max $ zipWith (-) from [0..]
          to' = zipWith (+) to [1..]
      return $ maximum $ zipWith (+) from' to'

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    ans <- solve <$> getInput
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  readInt = fst . fromJust . C.readInt
  getPair = do
    (a:b:_) <- map readInt . C.words <$> C.getLine
    return (a, b)
  getInput = do
    (n, s) <- getPair
    p <- replicateM n getPair
    return (s, p)

-- -----------------------------------------------------------------------------
-- IntMap-like Tree

data Tree a
  = Bin {-# UNPACK #-} !Word64    -- ^ Prefix
        {-# UNPACK #-} !Word64    -- ^ Mask
        !(Max a)                  -- ^ Aggregate value
        !(Tree a)                 -- ^ Left
        !(Tree a)                 -- ^ Right
  | Tip {-# UNPACK #-} !Word64    -- ^ Key
        !a                        -- ^ Value
  | Nil

getValue :: (Bounded a, Ord a) => Tree a -> Max a
getValue !root = case root of
  Bin _ _ value _ _ -> value
  Tip _ value -> Max value
  Nil -> mempty

prefixMask :: Word64 -> Word64 -> (Word64, Word64)
prefixMask !a !b = (prefix, mask)
  where
  !prefix = a .&. b .&. complement (mask - 1)
  !mask = m `xor` (m `unsafeShiftR` 1)
    where
    m = f 32 . f 16 . f 8 . f 4 . f 2 . f 1 $ a `xor` b
    f !k !i = i .|. unsafeShiftR i k

-- a_k += 1
bump :: (Bounded a, Num a, Ord a) => Word64 -> Tree a -> Tree a
bump !k = go
  where
  go bin@(Bin prefix mask v l r)
    | k < prefix = Bin prefix' mask' v (Tip k 1) bin
    | k >= prefix + (mask `unsafeShiftL` 1) = Bin prefix' mask' v bin (Tip k 1)
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
    | k >= prefix + (mask `unsafeShiftL` 1) = mempty
    | k .&. mask == 0 = query k l <> getValue r
    | otherwise = query k r
  go (Tip i v)
    | i >= k = Max v
    | otherwise = mempty
  go Nil = mempty

-- #30: 11044 ms  76100 KB
-- #40: 19560 ms  77100 KB
-- #48: 28484 ms  68900 KB

-- > prefix + (mask `unsafeShiftL` 1)
-- is faster than
-- > prefix + mask + mask
