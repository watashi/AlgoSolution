import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.Map as M
import qualified Data.ByteString.Char8 as C

gao s@(sx,sy) t@(tx,ty) e =
  if M.member s d && M.member t d
    then fromJust $ M.lookup t $ bfs [s] (M.insert s 0 d)
    else -1
  where
    d = M.fromList [((i, j), -1) | [i, l, r] <- e, j <- [l .. r]]
    bfs [] d = d
    bfs (v@(x,y):vs) d = bfs (vs ++ w) $ foldl (\i k -> M.insert k t i) d w
      where
        w = [(i, j) |
            i <- [x - 1 .. x + 1],
            j <- [y - 1 .. y + 1],
            M.lookup (i, j) d == Just (-1)]
        t = succ $ fromJust $ M.lookup v d

main = do
  [x0, y0, x1, y1] <- getArray
  [n] <- getArray
  e <- replicateM n getArray
  print $ gao (x0, y0) (x1, y1) e
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
