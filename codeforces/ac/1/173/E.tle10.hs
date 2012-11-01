{-# OPTIONS_GHC -O2 -optc-O3 -funbox-strict-fields -XBangPatterns #-}
import Control.Monad
import Data.Array
import Data.List
import Data.Maybe
import Debug.Trace
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

update :: (a -> a) -> (a -> a -> a) -> Int -> Tree a -> Tree a
update f g i tree = go tree
  where
    info (Leaf _ c) = c
    info (Branch _ _ _ _ c) = c
    go v@(Leaf p c)
      | p == i    = Leaf p $ f c
      | otherwise = v
    go v@(Branch pl pr bl br c)
      | pl <= i && i <= pr  = Branch pl pr bl' br' $ g (info bl') (info br')
      | otherwise           = v
      where
        bl' = go bl
        br' = go br

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

newCounterTree :: [(Int, a)] -> Tree Int
newCounterTree = newTree (const 0)

updateCount :: Int -> (Int -> Int) -> Tree Int -> Tree Int
updateCount i f = update f (+) i

queryCount :: Int -> Int -> Tree Int -> Int
queryCount l r tree = query id (+) 0 l r tree

newDescQueueTree :: [(Int, (Int, Int))] -> Tree DescQueue
newDescQueueTree = newTree (newDescQueue . map snd)

queryTop :: Int -> Int -> Int -> Tree DescQueue -> Int
queryTop l r x tree = query (top x) max (-1) l r tree

gao :: Int -> Int -> [Int] -> [Int] -> Int -> Int -> Int
gao n m r a i j = go i j
  where
    arr = listArray (1, n) $ zip a r
    dict = M.toAscList $ M.fromListWith (++) [(i, [j]) | (i, j) <- zip a r]
    zero = newCounterTree $ zip (map head $ group $ sort r) $ repeat undefined
    peak = scan zero dict [] dict
      where
        scan st [] _ _ = []
        scan st ((a,e):t) x y = (a,(k,v)): scan st' t x' y'
          where
            k = maximum e
            v = queryCount 0 k st'
            (insert, y') = span (\(i,_) -> i <= a + m) $! y
            (delete, x') = span (\(i,_) -> i < a - m) $! x ++ insert
            st' = foldl (\k (i, j) -> updateCount i j k) st $
              [(i, succ) | i <- concatMap snd $! insert] ++
              [(i, pred) | i <- concatMap snd $! delete]
    tree = newDescQueueTree peak
    go x y = queryTop l r x tree
      where
        (a', r') = unzip [arr!i, arr!j]
        l = maximum a' - m
        r = minimum a' + m
        x = maximum r'

main = do
  [n, k] <- getArray
  r <- getArray
  a <- getArray
  [m] <- getArray
  q <- replicateM m getArray
  putStr $ unlines $ map show $ [f i j | f <- [gao n k r a], [i, j] <- q]
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

-- Time limit exceeded on test 10
