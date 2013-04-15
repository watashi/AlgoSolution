import Control.Arrow
import Control.DeepSeq
import Data.Array
import Data.List
import Data.Maybe
import qualified Data.Array.Unboxed as U
import qualified Data.ByteString.Char8 as C

kmp :: Eq a => Array Int a -> Array Int Int
kmp a = pre
  where
    ix = bounds a
    pre = listArray ix $ map f $ range ix
    f i
      | i == fst ix = fst ix - 1
      | otherwise   = g $ pre!(i-1)
      where
        g j
          | a!(j+1) == a!i  = j + 1
          | inRange ix j    = g $ pre!j
          | otherwise       = fst ix - 1

auto :: (Ix a) => (a, a) -> Array Int a -> U.UArray (Int, a) Int
auto (cl, cr) a = U.array ix $ assocs $ to
  where
    (il, ir) = bounds a
    ix = ((il - 1, cl), (ir, cr))
    pre = kmp a
    to = listArray ix $ map f $ range ix
    f (i, c)
      | i < ir && a!(i+1) == c  = i + 1
      | i == il - 1             = i
      | otherwise               = force $ to!(pre!i, c)

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  (sh: st) <- fmap C.words C.getContents
  let el = zipWith (\i (j, k) -> (readInt j, (i, k))) [2..] $ pairs $ init st
      e = accumArray (flip (:)) [] (1, readInt sh) el
      s = last st
      n = C.length s
      a = listArray (1, n) $ C.unpack s
      to = auto charset a
      go (x, i) c = let j = to U.! (i, c) in force (if j == n then x + 1 else x, j)
      gao v i = foldl' (+) 0 [force $ c + gao w j |
        (w, d) <- e!v, let (c, j) = C.foldl' go (0::Int, i) d]
  print $ gao 1 0
  where
    charset = ('a', 'z')
