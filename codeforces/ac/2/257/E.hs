{-# OPTIONS_GHC -O2 -optc-Ofast -ignore-errors #-}
{-# LANGUAGE FlexibleInstances #-}
import Control.Monad
import Data.Array.Unboxed
import Data.Int
import Data.List (sort, sortBy)
import Data.Maybe
import Data.Ord
-- import Debug.Trace
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

type Map = M.IntMap ([Int] -> [Int])

insert :: Int -> Int -> Map -> Map
insert k v s = M.insertWith (.) k (v:) s

query :: Int -> Map -> [Int]
query k s = maybe [] ($[]) $ M.lookup k s

delete :: Int -> Map -> ([Int], Map)
delete k s = (maybe [] ($[]) v, s')
  where
    (v, s') = M.updateLookupWithKey (const $ const Nothing) k s

lt :: Int -> Map -> Int
lt k s = maybe 1 fst $ M.lookupLT k s

gt :: Int -> Map -> Int
gt k s = maybe 1000000007 fst $ M.lookupGT k s

instance Show ([Int] -> [Int]) where
  show = show . ($[])

data Info = Info {
    todo    :: [Int],
    outside :: Map,
    inside  :: Map,
    pup     :: Int,
    pdown   :: Int,
    now     :: Int64,
    pos     :: Int,
    ans     :: [[(Int, Int64)]]
  }
  deriving(Show)

count :: (a -> Bool) -> [a] -> Int
count f = length . filter f

solve :: Int -> [[Int]] -> [Int64]
solve n tsf = map snd $ sort $ concat $ ans $ snd $
    runState gao $ Info k M.empty M.empty 0 0 1 1 []
  where
    t = listArray (1, n) $ map (fromIntegral . (!!0)) tsf :: UArray Int Int64
    s = listArray (1, n) $ map (!!1) tsf :: UArray Int Int
    f = listArray (1, n) $ map (!!2) tsf :: UArray Int Int
    k = sortBy (comparing (t!)) [1 .. n]

    gao :: State Info ()
    gao = do
      -- debug <- gets show
      -- trace debug $ return ()
      at <- gets now
      cur <- gets pos
      -- todo -> outside
      (up, todo') <- gets $ span ((<=at) . (t!)) . todo
      modify $ \info -> info {
          outside = foldl (\i j -> insert (s!j) j i) (outside info) up,
          todo    = todo',
          pup     = pup   info + count ((>cur) . (s!)) up,
          pdown   = pdown info + count ((<cur) . (s!)) up
        }
      -- outside -> inside
      (down, outside') <- gets $ delete cur . outside
      modify $ \info -> info {
          inside  = foldl (\i j -> insert (f!j) j i) (inside info) down,
          outside = outside',
          pup     = pup   info + count ((>cur) . (f!)) down,
          pdown   = pdown info + count ((<cur) . (f!)) down
        }
      -- inside -> done
      (done, inside') <- gets $ delete cur . inside
      modify $ \info -> info {
          ans = zip done (repeat at): ans info,
          inside = inside'
        }
      -- next
      if M.null outside' && M.null inside'
        then
          when (not $ null todo') $ do
            modify $ \info -> info{now = t!head todo'}
            gao
        else do
          goup <- gets $ \info -> pup info >= pdown info
          let sub x = (length $ query x outside') + (length $ query x inside')
              minit x = if null todo'
                          then x
                          else min x $ fromIntegral $ t!head todo' - at
          if goup
            then do
              let delta = minit $ min (gt cur outside') (gt cur inside') - cur
              modify $ \info -> info {
                  now = at + fromIntegral delta,
                  pos = cur + delta,
                  pup = pup info - sub (cur + delta)
                }
            else do
              let delta = minit $ cur - max (lt cur outside') (lt cur inside')
              modify $ \info -> info {
                  now   = at + fromIntegral delta,
                  pos   = cur - delta,
                  pdown = pdown info - sub (cur - delta)
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

