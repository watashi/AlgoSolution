import Data.List
import Data.Maybe
import Data.Int
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  [n, x] <- fmap parse C.getLine
  a <- fmap (map fromIntegral . parse) C.getLine
  let m = minimum a :: Int64
      t = x - 1
      (l, r) = span (<=t) $ elemIndices m a
      s = head $ reverse l ++ reverse r
      b =
        if s <= t
          then [if s < i && i <= t then m + 1 else m | i <- [0 .. n - 1]]
          else [if i <= t || i > s then m + 1 else m | i <- [0 .. n - 1]]
      b' = [e - if i == s then sum b else 0 | (i, e) <- zip [0 ..] b]
  putStrLn $ unwords $ map show $ zipWith (-) a b'
  where
    parse = map (fst . fromJust . C.readInt) . C.words
