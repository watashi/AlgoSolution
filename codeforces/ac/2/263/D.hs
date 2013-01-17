import Data.Array
import Data.List
import Data.Maybe
import Data.Ord
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): (y, x): pairs z
pairs _ = []

main :: IO ()
main = do
  (n:_:_:el) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let e = accumArray (flip (:)) [] (1, n) $ pairs el
      gao v d p =
        case filter (`M.notMember` d) $ e!v of
          (w:_) -> gao w (M.insert w (M.size d) d) (w:p)
          _     -> let w = minimumBy (comparing (d M.!)) $ e!v in w: takeWhile (/=w) p
      ans = gao 1 (M.singleton 1 0) [1]
  print $ length ans
  putStrLn $ unwords $ map show ans

