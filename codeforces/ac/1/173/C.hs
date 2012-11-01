{-# OPTIONS_GHC -O2 -optc-O3 -funbox-strict-fields -XBangPatterns #-}
import Control.Monad
import Data.List
import Data.Maybe
import Data.Array.Base (unsafeAt)
import Data.Array.Unboxed (UArray, listArray, (!))
import qualified Data.ByteString.Char8 as C

solve :: Int -> Int -> [[Int]] -> Int
solve r c a = maximum $ [total i j | i <- [1 .. r], j <- [1 .. c]]
  where
    inf = 10000
    b = replicate (c+1) 0: map (0:) a
    e :: UArray Int Int
    e = listArray (0,(r+1)*(c+1)) $ concat b
    s :: UArray Int Int
    s = listArray (0,(r+1)*(c+1)) $ concat $ scanl1 (zipWith (+)) $ map (scanl1 (+)) b
    query !(x1, y1, x2, y2) =
      unsafeAt s (x2 * (c + 1) + y2) +
      unsafeAt s (x1 * (c + 1) + y1) -
      unsafeAt s (x1 * (c + 1) + y2) -
      unsafeAt s (x2 * (c + 1) + y1)
    total !x !y = maximum $ (-inf:) $ drop 1 $ scanl1 subtract $ center: map diff [1 .. m]
      where
        m = minimum [x - 1, y - 1, r - x, c - y]
        center = unsafeAt e (x * (c + 1) + y)
        diff z =
          query (x - z - 1, y - z - 1, x + z, y + z) -
          unsafeAt e ((x - z + 1) * (c + 1) + y - z)

main = do
  [r, c] <- getArray
  a <- replicateM r getArray
  print $ solve r c a
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

-- Time limit exceeded on test 19
