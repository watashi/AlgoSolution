{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad (replicateM)
import Data.Array (accumArray, (!))
import Data.Maybe (fromJust)
-- import Data.Sequence (fromList, index, update)
import Data.Map (fromList, lookup, insert)
import Prelude hiding (lookup)
import qualified Data.ByteString.Char8 as C

gao n a el = go [i | (i, j) <- zip [1 ..] a, j == 0] [] v
  where
    v = fromList $ zip [1 ..] a
    e = accumArray (flip (:)) [] (1, n) $ concat $
      [(i, i) | i <- [1 .. n]]: [[(i, j), (j, i)] | [i, j] <- el]
    go []    done _ = done
    go (h:t) done b =
      if fromJust (lookup h b) == 0
        then go t' (h:done) b'
        else go t done b
      where
        (t', b') = foldl f (t, b) $ e!h
        f (l, m) k = (if v == 0 then k:l else l, if v < -1 then m else insert k v m)
          where
            v = pred $ fromJust $ lookup k m

main = do
  [n, m] <- getArray
  e <- replicateM m getArray
  a <- getArray
  let ans = gao n a e
  print $ length $ ans
  putStrLn $ unwords $ map show $ ans
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

{-
Data.Sequence: Time limit exceeded on test 17

# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
2540867 	Nov 12, 2012 12:43:35 AM 	watashi 	D - Dispute 	Haskell 	Accepted 	1984 ms 	45148 KB
-}
