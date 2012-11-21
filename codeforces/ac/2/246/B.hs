import Data.Maybe
import qualified Data.ByteString.Char8 as C

main = do
  (n:a) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let m = sum a `mod` n
  print $ if m == 0 then n else n - 1
