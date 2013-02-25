import Control.Applicative
import Data.Maybe
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  (_:k:a) <- map (fst . fromJust . C.readInt) <$> C.words <$> C.getContents
  print $ maximum $ [f - max 0 (t - k) | (f, t) <- pairs a]
