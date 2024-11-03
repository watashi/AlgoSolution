import Control.Monad
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C

readInt :: ByteString -> Int
readInt = maybe (error "readInt") fst . C.readInt

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n: k: _ <- readInts <$> C.getLine
    putStrLn $ if even $ quot (k + n `rem` 2) 2 then "YES" else "NO"

-- 289812278	Nov/03/2024 09:51UTC-8	watashi	2014B - Robin Hood and the Major Oak	Haskell	Accepted	77 ms	0 KB
