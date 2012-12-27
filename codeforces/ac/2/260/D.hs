import Control.Monad
import Data.Maybe
import qualified Data.Set as S
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

type PQ = S.Set (Int, Int)

data Info = Info {
  ws :: PQ,
  bs :: PQ,
  vs :: [(Int, Int)]
}

gao :: [[Int]] -> State Info [[Int]]
gao ans = do
  w <- gets ws
  b <- gets bs
  if S.null w || S.null b
    then do
      ((wv, bv): t) <- gets vs
      wvs <- forM (t ++ [(i, i) | (_, i) <- S.toList w]) $ \(i, _) -> do
        return [bv, i, 0]
      bvs <- forM [(i, i) | (_, i) <- S.toList b] $ \(_, i) -> do
        return [wv, i, 0]
      return $ ans ++ wvs ++ bvs
    else do
      (we, wv) <- gets (S.findMax . ws)
      modify $ \info -> info{ws = S.deleteMax $ ws info}
      (be, bv) <- gets (S.findMax . bs)
      modify $ \info -> info{bs = S.deleteMax $ bs info}
      let e = min we be
      case compare we be of
        EQ -> modify $ \info -> info{vs = (wv, bv): vs info}
        GT -> modify $ \info -> info{ws = S.insert (we - e, wv) $ ws info}
        LT -> modify $ \info -> info{bs = S.insert (be - e, bv) $ bs info}
      gao $ [wv, bv, e]: ans

main :: IO ()
main = do
  (n:cs) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let a = [(c, (s, i)) | (i, (c, s)) <- zip [1 .. n] $ pairs cs]
      w = S.fromList $ map snd $ filter ((==0) . fst) a
      b = S.fromList $ map snd $ filter ((==1) . fst) a
      ans = fst $ runState (gao []) $ Info w b []
  putStrLn $ unwords $ map show $ concat ans

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

