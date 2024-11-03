import Control.Monad
import Data.Array
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C
import Data.List (elemIndex)

readInt :: ByteString -> Int
readInt = maybe (error "readInt") fst . C.readInt

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n: d: k: _ <- readInts <$> C.getLine
    jobs <- replicateM k $ do
      l: r: _ <- readInts <$> C.getLine
      return [(max 1 $ l - d + 1, 1 :: Int), (r + 1, -1)]
    let
      a = accumArray (+) 0 (1, n + 1) $ concat jobs
      s = scanl1 (+) $ take (n - d + 1) $ elems a
      x = maybe 0 succ $ maximum s `elemIndex` s
      y = maybe 0 succ $ minimum s `elemIndex` s
    putStrLn $ show x ++ " " ++ show y

-- 289810220	Nov/03/2024 09:35UTC-8	watashi	2014D - Robert Hood and Mrs Hood	Haskell	Accepted	421 ms	74900 KB
