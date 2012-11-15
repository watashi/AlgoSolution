import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

par []    _ = []
par (h:t) b = length l: par t r
  where
    (l, r) = span (<h) b

gao a x b = length $ filter id $ zipWith (/=) a' b'
  where
    (_:a') = par x a
    (_:b') = par x b

main = do
  [n] <- getArray
  a <- replicateM n $ fmap (sort . tail) getArray
  print $ sum $ zipWith3 gao a (rotate a) $ rotate $ rotate a
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
    rotate (h:t) = t ++ [h]

