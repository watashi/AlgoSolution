import Data.Int
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  (_:input) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let a = pairs $ map fromIntegral input
      cmp (l1, p1) (l2, p2) = compare (l2 * p2 * (100 - p1)) (l1 * p1 * (100 - p2))
      b = sortBy cmp $ a
      gao (e, s) (l, p) = e `seq` s `seq` (e + l * p, s + l * 10000 + e * (100 - p))
      ans = snd $ foldl' gao (0, 0) b
  print $ (fromIntegral :: Int64 -> Double) ans / 10000
