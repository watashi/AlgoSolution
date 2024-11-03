{-# LANGUAGE BangPatterns #-}
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
    _n: k: _ <- readInts <$> C.getLine
    a <- readInts <$> C.getLine
    let
      gao !c _ [] = c :: Int
      gao !c !g (x: xs)
        | x == 0 && g > 0 = gao (c + 1) (g - 1) xs
        | x >= k = gao c (g + x) xs
        | otherwise = gao c g xs
    print $ gao 0 0 a

-- 289812849	Nov/03/2024 09:56UTC-8	watashi	2014A - Robin Helps	Haskell	Accepted	124 ms	0 KB
