import Control.Arrow
import Control.Monad.Trans.State.Strict
import Data.IntMap.Strict (IntMap)
import Data.Sequence
import qualified Data.IntMap.Strict as Map

push :: Int -> IntMap Int -> IntMap Int
push k = Map.insertWith (+) k 1

popMin, popMax :: IntMap Int -> (Int, IntMap Int)
(popMin, popMax) = (pop Map.deleteFindMin, pop Map.deleteFindMax)
  where
  pop df m = case df m of
    ((k, v), m') -> (k, if v > 1 then Map.insert k (v - 1) m' else m')
    
data Partition = Partition
  { balanced :: Bool
  , lt :: IntMap Int
  , gt :: IntMap Int
  }

add :: Int -> State Partition ()
add k = do
  b <- gets $ balanced
  if b
  then do
    k' <- state $ \p -> let (i, j) = popMin $ push k $ gt p in (i, p{ gt = j })
    modify $ \p -> p{ balanced = False, lt = push k' $ lt p }
  else do
    k' <- state $ \p -> let (i, j) = popMax $ push k $ lt p in (i, p{ lt = j })
    modify $ \p -> p{ balanced = True, gt = push k' $ gt p }

query :: Partition -> Int
query = fst . Map.findMax . lt

gao :: Int -> State (Seq Partition) Int
gao k = do
  if k >= 0
  then modify $ \ps -> case viewr ps of _ :> p -> ps |> add k `execState` p
  else modify $ \ps -> ps |> ps `index` (Data.Sequence.length ps + k)
  gets $ \ps -> case viewr ps of _ :> p -> query p

main :: IO ()
main = do
  (_:a) <- fmap (map read . lines) getContents
  let b = mapM gao a `evalState` (singleton $ Partition True Map.empty Map.empty)
  mapM_ print b