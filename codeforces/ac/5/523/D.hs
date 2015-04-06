import Control.Applicative
import Data.Int (Int64)
import Data.Maybe
import qualified Data.Set as S
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  (n:k:_) <- readInts
  gao n $ S.fromList [(0 :: Int64, i) | i <- [1..k]]
  where
  readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine
  gao 0 _ = return ()
  gao i q = do
    (s:m:_) <- map fromIntegral <$> readInts
    let ((k, v), q') = fromJust $ S.minView q
        e = max s k + m
    print e
    gao (i-1) $ S.insert (e, v) q'
