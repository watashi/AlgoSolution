import Control.Monad
import qualified Data.IntMap.Strict as Map

main :: IO ()
main = do
  re <- readLn
  ms <- replicateM re $ do
    a <- fmap (map read . words) getLine
    return $ buildM a
  let ans = foldl1 (Map.intersectionWith min) ms
  putStrLn $ unwords $ map show $ concat [[k, v] | (k, v) <- Map.assocs ans]
  where
  buildM (i:j:k) = Map.insert i j $ buildM k
  buildM _ = Map.empty