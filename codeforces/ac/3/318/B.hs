import Data.Int
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  str <- C.getLine
  let pre = C.findSubstrings (C.pack "heavy") str
      suf = C.findSubstrings (C.pack "metal") str
  print $ gao pre suf (length suf) (0::Int64)
  where
    gao [] _ _ s = s
    gao _ [] _ s = s
    gao a@(ah:at) b@(bh:bt) c s
      | ah < bh   = gao at b c (s + fromIntegral c)
      | otherwise = gao a bt (c - 1) s
