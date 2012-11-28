import Control.Monad
import Data.Set (Set, empty, insert, member)

main :: IO ()
main = do
  _ <- getLine
  input <- fmap words getLine
  let ans = fst $ runState (gao (reverse input)) empty
  putStrLn $ if ans then "YES" else "NO"

same :: String -> String -> Bool
same x y = or $ zipWith (==) x y

gao :: [String] -> State (Set (Int, String)) Bool
gao [] = return True
gao [_] = return True
gao [a,b] = return $ same a b
gao [a,b,c] = return $ same a b && same a c
gao (a:b:c:d:e) = do
  let key = (length e, a ++ b ++ c)
  done <- gets (member key)
  modify (insert key)
  if done
    then return False
    else liftM (not . null) $ filterM test [(a, b, a:c:d:e), (a, d, b:c:a:e)]
  where
    -- test (x, y, z) = liftM2 (&&) (return $ same x y) $ gao z -- wrong answer
    test (x, y, z) = if same x y then gao z else return False

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

