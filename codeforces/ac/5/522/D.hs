{-# LANGUAGE BangPatterns #-}
import Control.Applicative
import Control.DeepSeq
import Control.Monad
import Data.Array
import Data.Maybe
import qualified Data.ByteString.Char8 as C
import qualified Data.IntMap.Strict as M

main :: IO ()
main = do
  (n:m:_) <- readInts
  a <- readInts
  b <- forM [1..m] $ \i -> do
    (l:r:_) <- readInts
    return $ (r, ((l, i):))
  let q = force [(i, e []) | (i, e) <- assocs $ accumArray (.) id (1, n) b]
      r = gao M.empty M.empty (zip a q) []
      ans = elems $ array (1, m) r
  putStr $ unlines $ map show ans
  where
  readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine
  gao _ _ [] ans = ans
  gao !dist !prev ((k, (r, q)): t) ans = gao dist' prev' t $ go q ans
    where
    prev' = M.insert k r prev
    dist' = case M.lookup k prev of
      Just l -> insert l (r-l) dist
      Nothing -> dist
    go [] ret = ret
    go ((l, i): q') ret = go q' $ (i, minDist): ret
      where
      minDist = case M.lookupGE l dist' of
        Just (_, v) -> v
        Nothing -> -1
  insert !k !v !dist = case M.lookupGE k dist of
    Just (_, v') | v' <= v -> dist
    _ -> M.insert k v $ strip dist
    where
    strip m = case M.lookupLE k m of
      Just (k', v') | v' >= v -> strip $ M.delete k' m
      _ -> m
