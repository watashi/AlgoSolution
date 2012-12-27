import Control.Applicative
import Data.Array.Unboxed
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

dom :: UArray Int Int
dom = listArray (1,12) [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

parse :: C.ByteString -> Maybe C.ByteString
parse s =
  if C.elemIndices '-' s == [2, 5]
      && 2013 <= y && y <= 2015
      && 1 <= m && m <= 12
      && 1 <= d && d <= dom!m
    then Just s
    else Nothing
  where
    readInt = maybe 0 fst . C.readInt
    [d, m, y] = map readInt $ C.split '-' s

main :: IO ()
main = do
  input <- C.getLine
  let date = catMaybes $ map (parse . C.take 10) $ C.tails input
  C.putStrLn $ snd $ maximum $ map (liftA2 (,) length head) $ group $ sort $ date

