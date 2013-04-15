{-# LANGUAGE GeneralizedNewtypeDeriving #-}
import Data.Bits
import Data.List
import Data.Maybe
import Data.Word
import qualified Data.ByteString.Char8 as C

newtype IP = IP Word32
  deriving (Eq, Ord, Num, Bits)

instance Show IP where
  show (IP ip) = intercalate "." $ map show $
    reverse $ map (`mod`256) $ take 4 $ iterate (`div`256) $ ip

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

parse :: C.ByteString -> IP
parse s = IP $ foldl1 (\i j -> (i * 256 + j)) $ map (fromIntegral . readInt) $ C.split '.' s

clz :: (Num a, Bits a) => a -> Int
clz x
  | x == 0    = n
  | otherwise = m - until (testBit x) pred m
  where
    n = bitSize x
    m = n - 1

main :: IO ()
main = do
  (sn:sm:s) <- fmap C.words C.getContents
  let _ = readInt sn
      m = readInt sm
      a = sort $ map parse s
      b = [i | i <- masks, let j = map (.&. i) a, length (group j) == m]
  if null b
    then putStrLn "-1"
    else putStrLn $ show $ head b
  where
    masks = scanl1 (.|.) $ map (IP . bit) $ [31, 30 .. 0]
