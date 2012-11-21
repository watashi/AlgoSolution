import Control.Arrow
import Control.Applicative
import Control.Monad
import Data.Array
import Data.Function
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main = do
  (n:m:ve) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let (vl, el) = splitAt n ve
      v = listArray (1, n) vl
      e = accumArray (flip (:)) [] (1, n) $ concat [[(i, j), (j, i)] |
        [i, j] <- map (take 2) $ takeWhile (not . null) $ iterate (drop 2) el]
      g = groupBy ((==) `on` fst) $ sort $ zip vl [1 ..]
  ans <- forM (map (liftA2 (,) (fst . head) (map snd)) g) $ \(c, s) -> do
    let q = map head $ group $ sort $ map (v!) $ concatMap (e!) s
    return $ first negate $ (length q - if elem c q then 1 else 0, c)
  print $ snd $ minimum ans
