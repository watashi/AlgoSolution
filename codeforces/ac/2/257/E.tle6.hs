{-# OPTIONS_GHC -O2 -optc-Ofast -ignore-errors #-}
import Control.Monad
import Data.Array.Unboxed
import Data.Foldable (toList)
import Data.Int
import Data.List (sort, sortBy)
import Data.Maybe
import Data.Ord
import Data.Sequence ((><), ViewL(..), ViewR(..))
import qualified Data.Sequence as S
import qualified Data.ByteString.Char8 as C

type Map = S.Seq (Int, Int)

lowerBound :: Int -> Map -> Int
lowerBound k s = go 0 n
  where
    n = S.length s
    go l r
      | l == r                = r
      | fst (S.index s m) < k = go (m + 1) r
      | otherwise             = go l m
      where
        m = (l + r) `div` 2

splitBy :: Int -> Map -> (Map, Map)
splitBy k s = S.splitAt (lowerBound k s) s

insert :: Int -> Int -> Map -> Map
insert k v s = l >< S.singleton (k, v) >< r
  where
    (l, r) = splitBy k s

delete :: Int -> Map -> ([Int], Map)
delete k s = (map snd $ toList v, l >< r')
  where
    (l, r) = splitBy k s
    (v, r') = S.spanl ((==k) . fst) r

data Info = Info {
    todo    :: [Int],
    outside :: Map,
    inside  :: Map,
    now     :: Int64,
    pos     :: Int,
    ans     :: [[(Int, Int64)]]
  }
  deriving(Show)

solve :: Int -> [[Int]] -> [Int64]
solve n tsf = map snd $ sort $ concat $ ans $ snd $
    runState gao $ Info k S.empty S.empty 0 1 []
  where
    inf = 1000000007

    t = listArray (1, n) $ map (fromIntegral . (!!0)) tsf :: UArray Int Int64
    s = listArray (1, n) $ map (!!1) tsf :: UArray Int Int
    f = listArray (1, n) $ map (!!2) tsf :: UArray Int Int
    k = sortBy (comparing (t!)) [1 .. n]

    gao :: State Info ()
    gao = do
      at <- gets now
      cur <- gets pos
      -- todo -> outside
      (up, todo') <- gets $ span ((<=at) . (t!)) . todo
      modify $ \info -> info {
          outside = foldl (\i j -> insert (s!j) j i) (outside info) up,
          todo = todo'
        }
      -- outside -> inside
      (down, outside') <- gets $ delete cur . outside
      modify $ \info -> info {
          inside = foldl (\i j -> insert (f!j) j i) (inside info) down,
          outside = outside'
        }
      -- inside -> done
      (done, inside') <- gets $ delete cur . inside
      modify $ \info -> info {
          ans = zip done (repeat at): ans info,
          inside = inside'
        }
      -- next
      if S.null outside' && S.null inside'
        then
          when (not $ null todo') $ do
            modify $ \info -> info{now = t!head todo'}
            gao
        else do
          let (outl, outr) = splitBy cur outside'
              (inl,  inr)  = splitBy cur inside'
              lt = \i -> case S.viewr i of
                       EmptyR       -> 1
                       _ :> (a, _)  -> a
              gt = \i -> case S.viewl i of
                       EmptyL       -> inf
                       (a, _) :< _  -> a
              (dir, new) = if S.length outr + S.length inr >= S.length outl + S.length inl
                             then (1, min (gt outr) (gt inr))
                             else (-1, max (lt outl) (lt inl))
              delta = min (abs $ new - cur) $
                if null todo' then inf else fromIntegral $ t!head todo' - at
          modify $ \info -> info {
              now = at + fromIntegral delta,
              pos = cur + dir * delta
            }
          gao

main :: IO ()
main = do
  (n:_:r) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let tsf = take n $ map (take 3) $ iterate (drop 3) r
  putStr $ unlines $ map show $ solve n tsf

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

