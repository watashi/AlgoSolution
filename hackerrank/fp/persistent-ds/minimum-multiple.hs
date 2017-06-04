{-# LANGUAGE DataKinds #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}
{-# LANGUAGE RecordWildCards #-}

import Control.Applicative
import Control.Monad
import Control.Monad.Trans.State.Strict
import qualified Data.ByteString.Char8 as C
import Data.IntMap (IntMap)
import qualified Data.IntMap.Strict as Map
import Data.Maybe
import Debug.Trace
import GHC.TypeLits
import Prelude hiding (lcm)

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

type Number = IntMap Int

num :: Int -> Number
num 1 = Map.empty
num n = Map.fromListWith (+) $ go n 2
  where
  go i j
    | i == j = [(i, 1)]
    | r == 0 = (j, 1): go q j
    | otherwise = go i (j + 1)
    where
    (q, r) = i `quotRem` j

mul, lcm :: Number -> Number -> Number
mul = Map.unionWith (+)
lcm = Map.unionWith max

toMInt :: Number -> MInt
toMInt n = product [mint k ^ v | (k, v) <- Map.assocs n]

data SegTree = SegTree
  { stBegin :: Int
  , stEnd :: Int
  , stMul :: Number
  , stLcm :: Number
  , stLeft :: SegTree
  , stRight :: SegTree
  }

stMid :: SegTree -> Int
stMid SegTree{..} = stBegin + (stEnd - stBegin) `quot` 2

newSegTree :: Int -> Int -> SegTree
newSegTree stBegin stEnd = st
  where
  st = SegTree{..}
  stMul = num 1
  stLcm = num 1
  stLeft = newSegTree stBegin (stMid st)
  stRight = newSegTree (stMid st) stEnd

update :: Number -> Int -> Int -> SegTree -> SegTree
update n = go
  where
  stLcm_ = stLcm
  go begin end st@SegTree{..}
    | begin == stBegin && end == stEnd =
        st{ stMul = stMul `mul` n, stLcm = stLcm `mul` n }
    | otherwise =
        st{ stLcm = l `mul` stMul, stLeft = left, stRight = right }
    where
    mid = stMid st
    left = (if begin < mid then go begin (min mid end) else id) stLeft
    right = (if mid < end then go (max begin mid) end else id) stRight
    l = stLcm_ left `lcm` stLcm_ right

query :: Int -> Int -> SegTree -> Number
query begin end st@SegTree{..}
  | begin == stBegin && end == stEnd = stLcm
  | end <= mid = query begin end stLeft
  | mid <= begin = query begin end stRight
  | otherwise = query begin mid stLeft `lcm` query mid end stRight
  where
  mid = stMid st
  
main :: IO ()
main = do
  n <- readInt <$> C.getLine
  a <- map readInt . C.words <$> C.getLine
  let st = foldr ($) (newSegTree 0 n)
        [ update (num e) i (i+1)
        | (i, e) <- [0..] `zip` a
        ]
  m <- readInt <$> C.getLine
  q <- replicateM m $ do
    (op:args) <- C.words <$> C.getLine
    let (i:j:_) = map readInt args
    return $
      if C.head op == 'U'
      then do
        modify $ update (num j) i (i+1)
        return Nothing
      else do
        ret <- gets $ toMInt . query i (j + 1)
        return $ Just ret
  mapM_ print $ catMaybes $ sequence q `evalState` st
  where
  readInt s = let Just (i, _) = C.readInt s in i