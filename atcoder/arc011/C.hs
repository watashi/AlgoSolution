import Control.Monad
import qualified Data.Map as M

ok :: String -> String -> Bool
ok s t = null $ drop 1 $ filter not $ zipWith (==) s t

bfs :: [String] -> State (M.Map String String) ()
bfs s = do
  t <- liftM concat $ forM s $ \v -> do
    w <- gets $ map fst . filter (\(i, j) -> null j && ok v i) . M.toList
    forM_ w $ \i -> modify $ M.insert i v
    return w
  when (not $ null t) $ bfs t

main :: IO ()
main = do
  [a, b] <- fmap words getLine
  n <- fmap read getLine
  v <- replicateM n getLine
  let d = snd $ runState (bfs [a]) $ M.insert a a $ M.fromList $ zip (b:v) $ repeat ""
      ans = a: if a == b then [b] else reverse $ takeWhile (/=a) $ iterate (d M.!) b
  if null $ d M.! b
    then putStrLn "-1"
    else do
      print $ length ans - 2
      putStr $ unlines ans

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

