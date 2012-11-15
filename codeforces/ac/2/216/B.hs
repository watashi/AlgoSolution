import Control.Monad
import Control.Monad.ST
import qualified Data.Map as S

newtype State a = State {
    runState :: S.Map Int Int -> (a, S.Map Int Int)
  }

instance Monad State where
  return a = State $ \s -> (a, s)
  m >>= k  = State $ \s -> let (a', s') = runState m s in runState (k a') s'

get = State $ \s -> (s, s)

set i p = State $ \s -> ((), S.insert i p s)

find i
  | i < 0     = do
    r <- find $ -i
    return $ -r
  | otherwise = do
    ds <- get
    case S.lookup i $ ds of
      Nothing -> return i
      Just p  -> do
        r <- find p
        set i p
        return r

union i j = do
  i <- find i
  j <- find j
  if i < 0 then
    union (-i) (-j)
  else if i + j == 0 then
    return False
  else do
    set i j
    return True

withDisjoinSet f = fst $ (runState f) S.empty

gao n e = do
  s <- forM e $ \[i, j] -> do
    b <- union i $ -j
    return $ if b then 0 else 1
  return $ n - (n - sum s) `div` 2 * 2

main = do
  [n, m] <- fmap (map read . words) getLine
  e <- replicateM m $ fmap (map read . words) getLine
  print $ withDisjoinSet $ gao n e

