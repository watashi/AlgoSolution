import Control.Monad
import Data.List
import System.IO

gao :: Int -> [Int] -> IO String
gao 3 [row] = do
  mapM_ print [5 * row + i + 1 | i <- [3 .. 4]]
  hFlush stdout
  s <- replicateM 2 $ head <$> getLine
  return $ reverse s
gao col rows = do
  mapM_ print [5 * i + col + 1 | i <- rows]
  hFlush stdout
  s <- replicateM (length rows) $ head <$> getLine
  let ((_,c):_) = sort [(length i, head i) | i <- group $ sort s]
  (c:) <$> gao (col + 1) [i | (i, j) <- rows `zip` s, j == c]

main :: IO ()
main = do
  (re:_) <- map read . words <$> getLine
  replicateM_ re $ do
    ans <- gao 0 [0 .. 118]
    putStrLn ans
    hFlush stdout
    "Y" <- getLine
    return ()
