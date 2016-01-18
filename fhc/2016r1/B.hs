import Control.Monad
import Control.Monad.Trans.State
import Control.Parallel.Strategies
import Data.Array
import Data.Maybe
import Data.Int (Int64)
import qualified Data.Set as Set
import qualified Data.ByteString.Char8 as C

type Time = Int64

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

wash :: Int -> [Time] -> [Time]
wash n w = gao n [] `evalState` s
  where
  d = listArray (0, length w - 1) w
  s = Set.fromList $ zip w [0..]
  gao 0 acc = return $ reverse acc
  gao k acc = do
    (t, i) <- state $ fromJust . Set.minView
    modify' $ Set.insert (t + d!i, i)
    gao (k-1) (t: acc)

dry :: Int -> Time -> [Time] -> [Time]
dry n d s = elems t
  where
  (sl, sr) = splitAt n s
  t = listArray (0, length s - 1) $
    map (+d) sl ++ [max e (t!i) + d | (i, e) <- zip [0..] sr]

solve :: (Int, [Int], Int, Int) -> Time
solve (n, w, m, d) = last $ dry m (fromIntegral d) $ wash n (map fromIntegral w)

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = runEval $ parList rdeepseq $ map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    (n:_:m:d:_) <- map readInt . C.words <$> C.getLine
    w <- map readInt . C.words <$> C.getLine
    return (n, w, m, d)
