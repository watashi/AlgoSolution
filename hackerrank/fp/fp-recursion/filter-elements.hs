import Control.Applicative
import Control.Monad
import Control.Monad.Trans.State.Strict
import qualified Data.IntSet as Set
import Data.List

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    let getInts = map read . words <$> getLine
    (n:m:_) <- getInts
    a <- getInts
    let s = Set.fromList [e | i@(e:_) <- group $ sort a, length i >= m]
        ans = concat $ flip evalState s $ forM a $ \i -> do
          f <- gets $ Set.member i
          if not f then return [] else do
          modify $ Set.delete i
          return [i]
    putStrLn $ if null ans then "-1" else unwords $ map show ans
    