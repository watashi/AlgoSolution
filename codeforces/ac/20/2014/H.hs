import Control.Monad
import Data.Array
import Data.Bits (xor)
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C
import GHC.Fingerprint

readInt :: ByteString -> Int
readInt bs = let Just (i, _) = C.readInt bs in i

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    (n:q:_) <- readInts <$> C.getLine
    a <- C.words <$> C.getLine
    let
      b = listArray (0, n) $
        scanl fpXor z $
        map (fingerprintString . C.unpack) a
    replicateM_ q $ do
      (l:r:_) <- readInts <$> C.getLine
      putStrLn $ if fpXor (b ! r) (b ! (l - 1)) == z then "YES" else "NO"
  where
    z = Fingerprint 0 0
    fpXor (Fingerprint ah al) (Fingerprint bh bl) =
      Fingerprint (ah `xor` bh) (al `xor` bl)

-- 286633110	Oct/18/2024 20:24UTC-7	watashi	2014H - Robin Hood Archery	Haskell	Accepted	656 ms	27400 KB
