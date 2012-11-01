import Control.Monad
import Data.Array
import Data.Maybe
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

type Counter = M.IntMap Int

newCounter :: [Int] -> Counter
newCounter a = M.fromList $ scanl1 (\(_, s) (k, v) -> (k, s + v)) $
  M.toAscList $ M.fromListWith (+) [(i, 1) | i <- a]

count :: Int -> Counter -> Int
count x c = case M.lookupLE x c of
                 Just (_, v)  -> v
                 Nothing      -> 0

type DescQueue = M.IntMap Int

newDescQueue :: [(Int, Int)] -> DescQueue
newDescQueue a = M.fromList $ trim $ M.toAscList $ M.fromListWith max a
  where
    trim [i] = [i]
    trim ((k,v):t) = if v > v' then (k,v):t' else t'
      where
        t'@((k',v'):_) = trim t

top :: Int -> DescQueue -> Int
top x c = case M.lookupGE x c of
               Just (_, v)  -> v
               Nothing      -> -1

data Tree a
  = Leaf Int a
  | Branch Int Int (Tree a) (Tree a) a
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
query f g z l r tree = go l r tree
  where
    go l r (Leaf p c)
      | l <= p && p <= r  = f c
      | otherwise         = z
    go l r (Branch pl pr bl br c)
      | l' == pl && r' == pr  = f c
      | l' <= r'              = g (go l' r' bl) (go l' r' br)
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
gao n m r a i j = tree `seq` rmq `seq` go i j
  where
    arr = listArray (1, n) $ zip a r
    dict = M.fromListWith (++) $ zipWith (\i j -> (i, [j])) a r
    tree = newCounterTree $ M.assocs $ dict
    peak = M.mapWithKey (\k v -> let w = maximum v in (w, queryCount (k-m) (k+m) w tree)) dict
    rmq = newDescQueueTree $ M.assocs $ peak
    go x y = queryTop l r x rmq
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
