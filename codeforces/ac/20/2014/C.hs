import Control.Monad
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C
import Data.List (sort)

readInt :: ByteString -> Int
readInt = maybe (error "readInt") fst . C.readInt

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n <- readInt <$> C.getLine
    a <- sort . readInts <$> C.getLine
    let
      bar = a !! quot n 2
      target = bar * n * 2 + 1
      total = sum a
    if n <= 2
    then putStrLn "-1"
    else print $ max 0 $ target - total

-- 289811519	Nov/03/2024 09:45UTC-8	watashi	2014C - Robin Hood in Town	Haskell	Accepted	312 ms	30700 KB
