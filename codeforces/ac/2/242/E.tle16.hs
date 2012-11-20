{-# OPTIONS_GHC -O2 -optc-O3 -fignore-asserts #-}
import Control.Monad (replicateM)
import Data.Bits (testBit, xor)
import Data.Maybe (fromJust)
-- import Data.Tuple (swap)
import Debug.Trace (trace)
import qualified Data.ByteString.Char8 as C

size = 20

newtype Info = Info {
    unInfo :: [Int]
  }
  deriving (Show)

empty = fromList []

fromList :: [Int] -> Info
fromList a = Info one
  where
    n = length a
    count i = length $ filter (`testBit` i) a
    one = map count [0 .. size - 1]

normalize n tag info
  | tag == 0  = info
  | otherwise = Info [if testBit tag i then n - j else j | (i, j) <- zip [0 ..] $ unInfo info]

combine a b = Info $ zipWith (+) (unInfo a) (unInfo b)

accumulate :: Info -> Integer
accumulate = foldr (\i s -> s * 2 + fromIntegral i) 0 . unInfo

-- Tree
data Tree
  = Leaf {
    p     :: Int,
    tag   :: Int,
    info  :: Info
  }
  | Branch {
    pl    :: Int,
    pr    :: Int,
    tag   :: Int,
    info  :: Info,
    bl    :: Tree,
    br    :: Tree
  }
  deriving (Show)

newTree :: [Int] -> Tree
newTree a = go 0 (length a) a
  where
    go l r a
      | r-l == 1  = Leaf l 0 info
      | otherwise = Branch l r 0 info (go l m al) (go m r ar)
      where
        m = (l + r) `div` 2
        info = fromList a
        (al, ar) = splitAt (m - l) a

count :: Tree -> Int
count Leaf{} = 1
count Branch{ pl = pl, pr = pr } = pr - pl

getInfo :: Tree -> Info
getInfo tree = normalize (count tree) (tag tree) (info tree)

updateTag :: Int -> Tree -> Tree
updateTag x tree =
  tree { tag = xor x $ tag tree }

dump :: Tree -> Tree
dump tree@Branch{tag = tag, info = info, bl = bl, br = br} =
  tree {
    tag   = 0,
    info  = normalize (count tree) tag info,
    bl    = updateTag tag bl,
    br    = updateTag tag br
  }

update :: Int -> Int -> Int -> Tree -> Tree
update l r x tree = go tree
  where
    go tree@Leaf{ p = p }
      | l <= p && p < r       = updateTag x tree
      | otherwise             = tree
    go tree@(Branch pl pr tag info bl br)
      | l' >= r'              = tree
      | l' == pl && r' == pr  = updateTag x tree
      | tag /= 0              = go $ dump tree
      | otherwise             = tree {
                                  tag   = 0,
                                  info  = combine (getInfo bl') (getInfo br'),
                                  bl    = bl',
                                  br    = br'
                                }
      where
        l' = max l pl
        r' = min r pr
        bl' = go bl
        br' = go br

query :: Int -> Int -> Tree -> (Integer, Tree)
query l r tree = go tree
  where
    go tree@(Leaf p tag info)
      | l <= p && p < r       = (accumulate $ normalize 1 tag info, tree)
      | otherwise             = (0, tree)
    go tree@(Branch pl pr tag info bl br)
      | l' >= r'              = (0, tree)
      | l' == pl && r' == pr  = (accumulate $ normalize (pr - pl) tag info, tree)
      | tag /= 0              = go $ dump tree
      | otherwise             = (il + ir, tree { bl = bl', br = br' })
      where
        l' = max l pl
        r' = min r pr
        (il, bl') = go bl
        (ir, br') = go br

--
main = do
  (n:input) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let (a,(m:q)) = splitAt n input
  putStr $ unlines $ map show $ gao (newTree a) q

gao tree (1:l:r:t) = ans': gao tree' t
  where
    (ans', tree') = query (l-1) r tree

gao tree (2:l:r:x:t) = gao tree' t
  where
    tree' = update (l-1) r x tree

gao _ _ = []

{-
#13: n=1000   m=503/1000    62ms
#14: n=1000   m=24962/50000 2375ms  1953ms
#15: n=50000  m=506/?       312ms
#16: n=50000
-}

-- Time limit exceeded on test 16
