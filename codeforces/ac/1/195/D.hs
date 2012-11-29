import Data.Ratio
import Data.Maybe
import Data.Set hiding (map)
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  (_:a) <- fmap (map (fst . fromJust . C.readInteger) . C.words) $ C.getContents
  let f (0:_:t) = f t
      f (k:b:t) = b%k: f t
      f _       = []
  print $ size $ fromList $ f a
