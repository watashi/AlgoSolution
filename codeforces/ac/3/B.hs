import Control.Applicative
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

main :: IO ()
main = do
  n <- head <$> readA
  a <- scanl1 (+) <$> replicateM n (product <$> readA)
  b <- readA
  putStr $ unlines $ map show $ gao (zip [(1::Int)..] a) b
  where
    readA = map readInt . C.words <$> C.getLine
    gao [] _ = []
    gao _ [] = []
    gao a@((i,e):t) b@(u:v)
      | u <= e    = i: gao a v
      | otherwise = gao t b
