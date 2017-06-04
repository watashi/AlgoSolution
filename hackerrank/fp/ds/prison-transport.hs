import Data.Graph
import Data.Tree
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  inputs <- C.getContents
  let (n:m:e) = [i | Just (i, _) <- map C.readInt $ C.words inputs]
      f n = until (\i -> i * i >= n) succ 1
      g = buildG (1, n) [(i, j) | (i:j:_) <- take m $ iterate (drop 2) e]
      h = sum $ map (f . length . flatten) $ components g
  print h