import Control.Applicative
import Data.Array
import Data.Int
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  (n:_:t) <- map (fst . fromJust . C.readInt) <$> C.words <$> C.getContents
  let (a, q) = splitAt n t
      (l, r) = unzip $ pairs q
      x = accumArray (+) 0 (0, n) $
        zip (map pred l) (repeat 1) ++ zip r (repeat $ -1)
      y = scanl1 (+) $ init $ elems x
      f = map fromIntegral . sort
      z = sum $ zipWith (*) (f a) (f y)
  print $ (z :: Int64)
