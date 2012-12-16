import Control.Applicative
import Control.Monad
import Data.Array
import Control.DeepSeq
import Data.Bits
import Data.List
import qualified Data.Map as M

main :: IO ()
main = do
  [_, m, y, z] <- fmap (map read . words) getLine
  x <- fmap M.fromList $ replicateM m $
    fmap (\i -> let [c, p] = words i in (head c, read p)) getLine
  s <- getLine

  let mask = 1 `shiftL` m - 1
      ix = ((0, 0), (mask, m - 1))
      undef = -1000000007
      c2i = M.fromList $ zip (map fst $ M.toList x) [0 ..]
      dp0 = listArray ix $ repeat undef :: Array (Int, Int) Int
      ans = foldl' gao dp0 $ map (liftA2 (,) (c2i M.!) (x M.!)) $ s
      gao dp (k, xk) = force ret
        where
          old = assocs dp
          new = [((i .|. bit k, k), e + xk + if j == k then y else 0) | ((i, j), e) <- old]
          ret = accumArray max undef ix $ ((bit k, k), xk): old ++ new
  print $ maximum $ (0:) $ elems $ ans // [((mask, i), ans!(mask, i) + z) | i <- [0 .. m - 1]]
