import Control.Monad (forM, forM_)
import Data.Array (accumArray, array, assocs, (!))
import Data.Graph (flattenSCC, stronglyConnComp)
import Data.List (group, sort)
import qualified Data.Array.Unboxed as A
import qualified Data.Map as M

inf = 10000

fromList a = M.fromList $ zip b [0 ..]
  where
    b = map head $ group $ sort a

pairs (x:y:z) = (x, y): pairs z
pairs _ = []

count f = length . filter f

main = do
  getLine
  a <- fmap words getContents
  let m = fromList a
      n = M.size m
      v = array (0,n-1) $ map (\(i, j) -> (j, i)) $ M.assocs m
      e = accumArray (flip (:)) [] (0,n-1) $
        concat [[(i, j), (j, i)] | (i, j) <- pairs $ map (m M.!) a]
      scc = map flattenSCC $ stronglyConnComp [(i, i, t)  | (i, t) <- assocs e]

  ans <- fmap concat $ forM scc $ \g -> do
    let mg = fromList g
        ng = M.size mg
        sub i = (mg M.! i, map (mg M.!) $ e!i)
        w :: A.UArray (Int, Int) Int
        w = A.accumArray (+) 0 ((0,0),(ng-1,ng-1)) $ concat $ [((i,i),-inf) | i <- [0 .. ng-1]]:
          [((i,j),-inf): [((j,k),1) | k <- t] | (i, t) <- map sub g, j <- t]
    forM (M.assocs mg) $ \(k, i) -> do
      let a = [w A.! (i,j) | j <- [0 .. ng-1]]
          d = maximum a
          c = case compare d 0 of
                GT -> count (==d) a
                EQ -> count (==0) a + (n - ng)
                LT -> n - ng
      return (v!k, c)

  print n
  forM_ ans $ \(i, j) -> do
    putStrLn $ i ++ " " ++ show j
