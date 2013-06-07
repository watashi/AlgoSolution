import Control.Monad
import Data.Graph
import Data.Tree

readPair :: IO (Int, Int)
readPair = do
  [a, b] <- fmap (map read . words) getLine
  return (a, b)

main :: IO ()
main = do
  (n, m) <- readPair
  e <- replicateM m readPair
  let g = buildG (1, n) e
      c = map flatten $ components g
      f l a = filter ((==l) . length) a
      one = f 1 c
      two = f 2 c
      three = f 3 c
  if maximum (map length c) > 3 || length two > length one then putStrLn "-1"
  else do
    let (x, y) = splitAt (length two) one
        ans = (three ++) $ (zipWith (++) x two ++) $
          map (concat . take 3) $ takeWhile (not . null) $ iterate (drop 3) $ y
    forM_ ans $ \i -> do
      putStrLn $ unwords $ map show $ i
