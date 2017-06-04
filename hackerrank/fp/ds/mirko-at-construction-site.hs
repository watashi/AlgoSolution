import Control.Arrow
import Control.Monad
import Data.Array
import Data.Function
import Data.List
import Data.Ord
import Data.Ratio
import qualified Data.ByteString.Char8 as C

inf :: Int
inf = 0x80000000

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f = go
  where
  go lo hi
    | lo == hi = hi
    | f mi = go lo mi
    | otherwise = go (mi+1) hi
    where
    mi = lo + (hi - lo) `quot` 2

main :: IO ()
main = do
  (n:m:inputs) <- fmap (map readInt . C.words) C.getContents
  let (a, (b, q)) = second (splitAt n) $ splitAt n inputs
      (h:t) = map maximum $
        groupBy ((==) `on` fst) $
        sortBy (flip $ comparing fst) $
        zip b $ zip a [1..]
      (nskyline, skyline) = (nl, listArray (0, nl-1) l)
        where
        nl = length l
        l = foldl' push [(inf % 1, h)] t
      push [] _ = error "impossible"
      push j@((xj, (bj, (aj, ij))): k) i@(bi, (ai, ii)) = case compare xi xj of
        LT -> (xi, i): j
        GT -> push k i
        EQ -> case k of
          (_, (_, (_, ik))): l | ij > ii && ij > ik -> (xi, i): j
          _ -> (xi, i): k
        where
        xi = (ai - aj) % (bj - bi)
  forM_ (map fromIntegral q) $ \x -> do
    let k = bsearch (\i -> fst (skyline!i) >= x) 0 (nskyline-1)
        k' = until (\i -> i == nskyline - 1 || fst (skyline!i) > x) succ k
        ans = maximum [i | (_, (_, (_, i))) <- map (skyline!) [k .. k']]
    print ans
  where
  readInt s = let Just (i, _) = C.readInt s in i