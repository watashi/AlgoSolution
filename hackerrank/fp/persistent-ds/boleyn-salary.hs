{-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Monad
import Data.Array hiding (index)
import Data.Bits
import Data.Graph
import Data.Monoid
import Data.Tuple
import Data.Word (Word)
import qualified Data.ByteString.Char8 as C
import qualified Data.IntMap.Strict as Map

main :: IO ()
main = do
  (n:m:_) <- getInts
  e <- replicateM (n - 1) $ do
    (u:p:_) <- getInts
    return (p, u)
  let g = buildG (1, n) e
  s <- listArray (1, n) <$> getInts
  let r = Map.fromList $ map swap $ assocs s
      a = listArray (1, n) $ map f [1 .. n] :: Array Int (BitTree (Sum Int))
        where
        f v = unions [add (fromIntegral (s!w)) 1 (a!w) | w <- g!v]
  q <- replicateM m $ do
    (d:k:_) <- getInts
    return (d, k)
  let gao v (d, k) = r Map.! fromIntegral (index (Sum $ k-1) $ a!(v+d))
      (_:ans) = scanl gao 0 q
  mapM_ print ans
  where
  readInt s = let Just (i, _) = C.readInt s in i
  getInts = map readInt . C.words <$> C.getLine

data BitTree a
  = Bin Word Word a (BitTree a) (BitTree a)
  | Tip Word a
  | Nil
  deriving Eq

getValue :: Monoid a => BitTree a -> a
getValue root = case root of
  Bin _ _ value _ _ -> value
  Tip _ value -> value
  Nil -> mempty

prefixMask :: Word -> Word -> (Word, Word)
prefixMask !a !b = (prefix, mask)
  where
  !prefix = a .&. b .&. complement (mask - 1)
  !mask = m `xor` (m `unsafeShiftR` 1)
    where
    m = f 32 . f 16 . f 8 . f 4 . f 2 . f 1 $ a `xor` b
    f !k !i = i .|. unsafeShiftR i k

add :: Monoid a => Word -> a -> BitTree a -> BitTree a
add key value = go
  where
  tip = Tip key value
  go root@(Bin prefix mask v l r)
    | key < prefix = Bin prefix' mask' v' tip root
    | key >= prefix + mask + mask = Bin prefix' mask' v' root tip
    | mask .&. key == 0 = let t = go l in Bin prefix mask v' t r
    | otherwise = let t = go r in Bin prefix mask v' l t
    where
    v' = v <> value
    (prefix', mask') = prefixMask prefix key
  go root@(Tip k v) = case compare key k of
    LT -> Bin prefix mask v' tip root
    GT -> Bin prefix mask v' root tip
    EQ -> Tip k v'
    where
    v' = v <> value
    (prefix, mask) = prefixMask k key
  go Nil = tip

union :: Monoid a => BitTree a -> BitTree a -> BitTree a
union t1@(Bin p1 m1 v1 l1 r1) t2@(Bin p2 m2 v2 l2 r2)
  | p1 + m1 + m1 <= p2 = Bin prefix mask v t1 t2
  | p2 + m2 + m2 <= p1 = Bin prefix mask v t2 t1
  | m1 > m2 && m1 .&. p2 == 0 = Bin p1 m1 v (union l1 t2) r1
  | m1 > m2 && m1 .&. p2 /= 0 = Bin p1 m1 v l1 (union r1 t2)
  | m2 > m1 && m2 .&. p1 == 0 = Bin p2 m2 v (union l2 t1) r2
  | m2 > m1 && m2 .&. p1 /= 0 = Bin p2 m2 v l2 (union r2 t1)
  | otherwise = Bin p1 m1 v (union l1 l2) (union r1 r2)
  where
  v = v1 <> v2
  (prefix, mask) = prefixMask p1 p2
union (Tip k v) t = add k v t
union t (Tip k v) = add k v t
union Nil t = t
union t Nil = t

unions :: Monoid a => [BitTree a] -> BitTree a
unions = foldr union Nil

index :: (Monoid a, Num a, Ord a) => a -> BitTree a -> Word
index i (Bin _ _ _ l r) =
  let c = getValue l in if i < c then index i l else index (i - c) r
index i (Tip k v) | i < v = k
index _ _ = undefined
