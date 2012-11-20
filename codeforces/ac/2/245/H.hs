{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Data.Array (Array, assocs, listArray, (!))
import Data.Array.Unboxed (UArray, accumArray, array, elems)
import Data.Maybe (fromJust)
import Debug.Trace (trace)
import qualified Data.Array.Unboxed as U
import qualified Data.ByteString.Char8 as C

-- parsum = scanl1 (+)
-- parsum2 = parsum . parsum
parsum2 a = go 0 0 a
  where
    go s x [] = []
    go s x (h:t) = x': go s' x' t
      where
        s' = s + h
        x' = x + s'

-- O(n^2): 0.36s
palindrome s = [(l, r, go l r) | l <- [1 .. n], r <- [l, l + 1], r <= n]
  where
    n = C.length s
    a = listArray (1, n) $ C.unpack s
    go l r
      | l < 1 || r > n  = 0
      | a!l /= a!r      = 0
      | otherwise       = succ $ go (pred l) (succ r)

-- O(n): 0.02s
manacher s = [(div i 2, div (i + 1) 2, e) | (i, e) <- assocs b]
  where
    n = C.length s
    a = listArray (1, n) $ C.unpack s
    pal l r
      | l < 1 || r > n = 0
      | a!l /= a!r     = 0
      | otherwise      = succ $ pal (pred l) (succ r)
    b = listArray (2, 2*n) $ go 2 (0, 0)
    go k (e, c) = if l > n then [] else t: go (k + 1) (e', c')
      where
        l = div k 2
        r = k - l
        s = if k <= e then min (b!(2*c-k)) $ 1 + div (e-k) 2 else 0
        t = s + pal (l - s) (r + s)
        (e', c') = max (e, c) (2 * (r + t - 1), k)

solve :: C.ByteString -> [Int] -> [Int]
solve s q = go q
  where
    go [] = []
    go (l:r:t) = a ! l U.! r: go t
    n = C.length s
    p = manacher s
    a = listArray (1,n) $ map gao $ zip [1 .. n] $ iterate (drop 2) p
    gao :: (Int, [(Int, Int, Int)]) -> UArray Int Int
    gao (s, p) = U.listArray (s,n) $ parsum2 $ elems d
      where
        d :: UArray Int Int
        d = accumArray (+) 0 (s,n+1) $ concat [[(r, 1), (r + m', -1)] |
          (l,r,m) <- p,
          let m' = min m $ l - s + 1,
          m' > 0]

-- 4562ms
customTest = do
  let s = C.pack $ replicate 5000 'a'
      q = concat [[i, i + 1, i * 5, j * 5] | i <- [1 .. 1000], j <- [i .. 1000]]
  putStr $ unlines $ map show $ solve s q

main = do
  s <- C.getLine
  C.getLine
  q <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  putStr $ unlines $ map show $ solve s q
