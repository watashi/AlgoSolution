import Control.Monad
import Data.Array
import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao n e = concatMap (\i -> zip i $ drop 1 i) $ elems $ accumArray (flip (:)) [] (1,n) $
  concat $ zipWith (\k [i, j] -> [(i, k), (j, k)]) [1 ..] e

get = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

put = putStr . unlines . map (unwords . map show)

main = do
  [n] <- get
  e <- replicateM (n - 1) $ get
  put $ [[n - 1]]
  put $ map (2:) e
  put $ map (\(i, j) -> [i, j]) $ gao n e
