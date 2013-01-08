import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  (n:p) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let a@(h:t) = sort $ map (uncurry atan2) $ take n $ pairs $ map fromIntegral p
      b = maximum $ zipWith (-) (t ++ [h + 2 * pi]) a :: Double
  print $ 360 - 180 / pi * b
