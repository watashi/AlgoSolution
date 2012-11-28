{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
{-# LANGUAGE ParallelListComp #-}
import Control.Arrow (first)
import Control.Monad (forM, forM_)
import Data.Array (accumArray, listArray, (!))
import Data.Bits ((.&.), shiftL, shiftR)
import Data.List (sort)
import Data.Maybe (fromJust)
import qualified Data.IntSet as S
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

ctz :: Int -> Int
ctz n
  | n .&. 0xffff == 0 = ctz (n `shiftR` 16) + 16
  | n .&. 0x00ff == 0 = ctz (n `shiftR` 8) + 8
  | n .&. 0x000f == 0 = ctz (n `shiftR` 4) + 4
  | n .&. 0x0003 == 0 = ctz (n `shiftR` 2) + 2
  | otherwise         = 1 - (n .&. 1)

pairs :: [a] -> [(a, a)]
pairs (a:b:c) = (a, b): pairs c
pairs _ = []

main :: IO ()
main = do
  (n:input) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let (r, (_:q)) = splitAt n input
  putStrLn $ unwords $ map show $ solve n r $ pairs q

solve :: Int -> [Int] -> [(Int, Int)] -> [Int]
solve n r q = map snd $ sort $ snd $ runState (dfs 0 0 S.empty) []
  where
    e = accumArray (flip (:)) [] (0, n) $ zip r [1 ..]
    p = listArray (0, n) $ 0: r
    ps = listArray (0, 17) $ p:[
      listArray (0, n) [half!(half!j) | j <- [0 .. n]]
      | i <- [1 .. 17], let half = ps!(i - 1)]
    ancestor v 0 = v
    ancestor v d = let k = ctz d in ancestor (ps!k!v) (d - (1 `shiftL` k))
    query = M.fromListWith (++) $
      [(ancestor v d, [(d, i)]) | (v, d) <- q | i <- [0 ..]]

    dfs :: Int -> Int -> S.IntSet -> State [(Int, Int)] (M.IntMap Int)
    dfs v d s = do
      let qv = map (first (+d)) $ M.findWithDefault [] v query
          new = filter (`S.notMember` s) $ map fst $ qv
          s' = foldr S.insert s new
      children <- forM (e!v) $ \w -> dfs w (d + 1) s'

      let stat = foldr (M.unionWith (+)) M.empty children
      forM_ qv $ \(k, i) -> do
        let cnt = M.findWithDefault 0 k stat
        modify ((i, if v == 0 || cnt == 0 then 0 else cnt - 1):)

      let stat' = foldr M.delete stat new
      if d `S.member` s
        then return $ M.insertWith (+) d 1 stat'
        else return stat'

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

