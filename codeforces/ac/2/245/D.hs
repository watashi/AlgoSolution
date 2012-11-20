import Control.Monad (replicateM)
import Data.Bits ((.|.))
import Data.Maybe (fromJust)
import qualified Data.ByteString.Char8 as C

main = do
  [n] <- getArray
  a <- replicateM n $ getArray
  putStrLn $ unwords $ map show $ map (foldr (.|.) 0 . filter (>=0)) a
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
