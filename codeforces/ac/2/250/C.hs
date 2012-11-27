import Data.Array
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

go [x, y] = [(y, 1)]
go (x:t@(y:z:_)) = (y, if x == z then 2 else 1): go t

main = do
  (n:m:a) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let b@(x:y:_) = map head $ group a
      c = [(-e, i) | (i, e) <- assocs $ accumArray (+) 0 (1,m) $ (x, 1): go b]
  print $ snd $ minimum c
