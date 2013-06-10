import Control.Monad.State
import qualified Data.Map as M

fib :: [Integer]
fib = 1: 2: zipWith (+) fib (tail fib)

gao :: Integer -> State (M.Map Integer Integer) Integer
gao n =
  if n <= 1
    then return 0
    else do
      cache <- gets $ M.lookup n
      case cache of
        Just ret  -> return ret
        Nothing   -> do
          let m = last $ takeWhile (<n) fib
          lo <- gao $ m
          hi <- gao $ n - m
          let total = lo + hi + (n - m)
          modify $ M.insert n total
          return total

main :: IO ()
main = print $ evalState (gao $ 10 ^ (17::Int)) M.empty
