import Control.Applicative
import Control.Monad.IO.Class
import Control.Monad.Trans.State.Strict
import qualified Data.ByteString.Char8 as C
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as Map

gao :: [Int] -> StateT (IntMap (IntMap Int)) IO ()
gao q0 = case q0 of
  (1:i:q) -> do
    k <- gets $ fst . Map.findMax . (Map.! i)
    liftIO $ print k
    gao q
  (2:i:q) -> do
    modify $ Map.adjust kill i
    gao q
  (3:i:c:q) -> do
    let m = Map.singleton c 1
    modify $ Map.insertWith merge i m
    gao q
  (4:i:j:q) -> do
    m <- gets (Map.! j)
    modify $ Map.insertWith merge i m . Map.delete j
    gao q
  _ -> return ()
  where
  kill = Map.updateMax $ \v -> if v > 1 then Just (v-1) else Nothing
  merge = Map.unionWith (+)
  
main :: IO ()
main = do
  (_:_:q) <- map readInt . C.words <$> C.getContents
  gao q `evalStateT` Map.empty
  where
  readInt s = let Just (i, _) = C.readInt s in i