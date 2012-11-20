{-# OPTIONS_GHC -O2 -optc-O3 -funbox-strict-fields -XBangPatterns #-}
import Control.Monad
import Data.Array
import Data.List
import Data.Maybe
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

type FakeIntMap = Array Int (Int, Int)

newFakeIntMap a = listArray (1, length a) a

lbound :: FakeIntMap -> Int
lbound = fst . bounds

rbound :: FakeIntMap -> Int
rbound = snd . bounds

upperBound :: Int -> FakeIntMap -> Int
upperBound x a = go s $ t + 1
  where
    (s, t) = bounds a
    go l r
      | l == r        = r
      | fst (a!m) > x = go l m
      | otherwise     = go (succ m) r
      where m = (l + r) `div` 2

type Counter = FakeIntMap

newCounter :: [Int] -> Counter
newCounter a = newFakeIntMap $ scanl1 (\(_, s) (k, v) -> (k, s + v)) $
  M.toAscList $ M.fromListWith (+) [(i, 1) | i <- a]

count :: Int -> Counter -> Int
count x c = let i = upperBound x c in if i == lbound c then 0 else snd $ c!(i-1)

type DescQueue = FakeIntMap

newDescQueue :: [(Int, Int)] -> DescQueue
newDescQueue a = newFakeIntMap $ trim $ M.toAscList $ M.fromListWith max a
  where
    trim [i] = [i]
    trim ((k,v):t) = if v > v' then (k,v):t' else t'
      where
        t'@((k',v'):_) = trim t

top :: Int -> DescQueue -> Int
top x c = let i = upperBound (x-1) c in if i > rbound c then -1 else snd $ c!i

data Tree a
  = Leaf !Int a
  | Branch !Int !Int (Tree a) (Tree a) a
  deriving (Show)

newTree :: ([(Int, a)] -> b) -> [(Int, a)] -> Tree b
newTree f a = go a
  where
    go a
      | n == 1    = Leaf l c
      | otherwise = Branch l r (go al) (go ar) c
      where
        n = length a
        m = length a `div` 2
        l = fst $ head a
        r = fst $ last a
        (al, ar) = splitAt m a
        c = f a

query :: (a -> b) -> (b -> b -> b) -> b -> Int -> Int -> Tree a -> b
query f g z l r tree = go tree
  where
    go (Leaf p c)
      | l <= p && p <= r  = f c
      | otherwise         = z
    go (Branch pl pr bl br c)
      | l' == pl && r' == pr  = f c
      | l' <= r'              = g (go bl) (go br)
      | otherwise             = z
      where
        l' = max l pl
        r' = min r pr

newCounterTree :: [(Int, [Int])] -> Tree Counter
newCounterTree = newTree (newCounter . concatMap snd)

queryCount :: Int -> Int -> Int -> Tree Counter -> Int
queryCount l r x tree = query (count x) (+) 0 l r tree

newDescQueueTree :: [(Int, (Int, Int))] -> Tree DescQueue
newDescQueueTree = newTree (newDescQueue . map snd)

queryTop :: Int -> Int -> Int -> Tree DescQueue -> Int
queryTop l r x tree = query (top x) max (-1) l r tree

gao :: Int -> Int -> [Int] -> [Int] -> Int -> Int -> Int
gao n m r a i j = go i j
  where
    arr = listArray (1, n) $ zip a r
    dict = M.assocs $ M.fromListWith (++) [(i, [j]) | (i, j) <- zip a r]
    tree = newCounterTree dict
    peak = [(k, (w, queryCount (k-m) (k+m) w tree)) | (k, v) <- dict, w <- [maximum v]]
    rmq = newDescQueueTree peak
    go x y = queryTop l r x rmq
      where
        (a', r') = unzip [arr!i, arr!j]
        l = maximum a' - m
        r = minimum a' + m
        x = maximum r'

pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main = do
  (n:k:input1) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let (r,input2) = splitAt n input1
      (a,input3) = splitAt n input2
      (m:q) = input3
  putStr $ unlines $ map show $ [f i j | f <- [gao n k r a], (i, j) <- pairs q]

-- Time limit exceeded on test 11
