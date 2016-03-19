import Control.Monad
import Data.Int (Int64)
import Data.Sequence (Seq)
import qualified Data.ByteString.Char8 as C
import qualified Data.Sequence as Seq

gao :: [(Int, Int)] -> Int -> Int64 -> Seq Int64 -> [Int64]
gao [] _ _ _ = []
gao r@((t, d): r') b m q
  | not (Seq.null q) && t' <= fromIntegral t = gao r (b+1) m q'
  | b /= 0 = end: gao r' (b-1) end (q Seq.|> begin)
  | otherwise = (-1): gao r' b m q
  where
  begin = max m $ fromIntegral t
  end = begin + fromIntegral d
  t' Seq.:< q' = Seq.viewl q

main :: IO ()
main = do
  (n:b:_) <- fmap (map readInt . C.words) C.getLine
  r <- replicateM n $ do
    (t:d:_) <- fmap (map readInt . C.words) C.getLine
    return (t, d)
  let ans = gao r b 0 Seq.empty
  putStrLn $ unwords $ map show ans
  where
  readInt s = let Just (i, _) = C.readInt s in i
