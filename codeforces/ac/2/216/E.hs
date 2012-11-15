import Data.List
import Data.Maybe
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

gao b 0 a = sum [i * (i + 1) `div` 2| i <- map toInteger c]
  where
    c = map length $ filter ((==0) . head) $ group a

gao b d a = c - if d == b - 1 then gao b 0 a else 0
  where
    (c, _, _) = foldl' go (0, 0, M.singleton 0 1) a
    go (x, s, m) t = (x', s', m')
      where
        t' = (s' - d) `mod` (b - 1)
        x' = x + toInteger (M.findWithDefault 0 t' m)
        s' = (s + t) `mod` (b - 1)
        m' = M.insertWith (+) s' 1 m

main = do
  [k, b, n] <- getArray
  a <- getArray
  print $ gao k b a
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
2564622 	Nov 15, 2012 9:29:55 PM 	watashi 	216E - Martian Luck 	Haskell 	Accepted 	515 ms 	73900 KB
-}
