import Control.Monad
import Control.Parallel.Strategies
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Int, Int, Double) -> Double
solve (n, k, p) = dp!n
  where
  e :: UArray Int Double
  e = listArray (0, n) . map (sum . drop k) . flip iterate [1] $ \i ->
    zipWith (+) (0: map (*p) i) (map (*(1-p)) i ++ [0])
  dp :: Array Int Double
  dp = listArray (0, n) . (0:) . flip map [1 ..] $ \i ->
    maximum $ 0: [dp!(i-j) + e!j | j <- [k .. i]]

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = runEval $ parList rdeepseq $ map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    (n:k:p:_) <- C.words <$> C.getLine
    return (readInt n, readInt k, read $ C.unpack p)
