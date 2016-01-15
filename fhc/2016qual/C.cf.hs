import Control.Applicative
import Control.Monad
import Data.Maybe
import Data.Int (Int64)
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Int, [Int]) -> Int64
solve (limit, list) = gao limit list list 0 0
  where
  gao _ [] _ _ s = s
  gao m as (b:bs) d s | m >= b = gao (m-b) as bs (d+1) s
  gao m (a:as) bs d s = gao (m+a) as bs (d-1) (s+d)

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    let readInts = map readInt . C.words <$> C.getLine
    (_:m:_) <- readInts
    a <- readInts
    return (m, a)
