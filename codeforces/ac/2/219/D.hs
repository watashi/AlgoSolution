{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Data.Array
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao n e = (root + diff, sort $ list [])
  where
    (root, diff, list) = dfs 1 1
    dfs v p = foldl f z $ map (\(i, j) -> (dfs i v, j)) $ filter ((/=p) . fst) $ e!v
        where
          z = (0, 0, (v:))
          f (s, sx, sy) ((t, tx, ty), d) =
            case compare sx tx' of
              LT -> (t', sx, sy)
              EQ -> (t', sx, sy . ty)
              GT -> (t', tx', ty)
            where
              (t', tx') = if d then (s + t, tx + 1) else (s + t + 1, tx - 1)

main = do
  (n:q) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let e = accumArray (flip (:)) [] (1, n) $ concat [[(i, (j, True)), (j, (i, False))] |
        [i, j] <- map (take 2) $ takeWhile (not . null) $ iterate (drop 2) q]
      (x, y) = gao n e
  putStrLn $ show x
  putStrLn $ unwords $ map show $ y
