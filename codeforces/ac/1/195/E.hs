{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad
import Data.Maybe
import Data.List (foldl')
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

(+%) :: Int -> Int -> Int
lhs +% rhs = (lhs + rhs) `mod` 1000000007

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

type DisjointSet = State (M.IntMap (Int, Int))

query :: Int -> DisjointSet (Int, Int)
query v = v `seq` do
  h@(hr, hd) <- gets (M.! v)
  if hr == v
    then return h
    else do
      (tr, td) <- query hr
      let ret = (tr, hd +% td)
      modify $ M.insert v ret
      return ret

process :: Int -> Int -> [Int] -> DisjointSet Int
process _ s [] = return s
process k s (m:q) = s `seq` do
  modify $ M.insert k (k, 0)
  edges <- forM (pairs e) $ \(v, x) -> do
    (root, depth) <- query v
    let depth' = depth +% x
    modify $ M.insert root (k, depth')
    return $ depth'
  process (k + 1) (s +% foldl' (+%) 0 edges) q'
  where
    (e, q') = splitAt (2*m) q

main :: IO ()
main = do
  (_:q) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  print $ fst $ runState (process 1 0 q) M.empty

-- Control.Monad.State
newtype State s a = State {
  runState :: s -> (a, s)
}

instance Monad (State s) where
  return a = State $ \s -> (a, s)
  m >>= f  = State $ \s -> let (a', s') = runState m s in runState (f a') s'

get :: State s s
get = State $ \s -> (s, s)

put :: s -> State s ()
put s = State $ \_ -> ((), s)

modify :: (s -> s) -> State s ()
modify f = State $ \s -> ((), f s)

gets :: (s -> a) -> State s a
gets f = State $ \s -> (f s, s)

