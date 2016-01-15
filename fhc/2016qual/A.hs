import Control.Monad
import Control.Parallel.Strategies
import Data.Maybe
import qualified Data.IntMap.Strict as Map
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: [(Int, Int)] -> Int
solve a = sum
  [ v * (v - 1) `quot` 2
  | (x, y) <- a
  , let d = [sqr (x - x') + sqr (y - y') | (x', y') <- a]
  , let c = Map.fromListWith (+) $ d `zip` repeat 1
  , v <- Map.elems c
  ]
  where
  sqr x = x * x

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = runEval $ parList rdeepseq $ map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    n <- readInt <$> C.getLine
    replicateM n $ do
      (x:y:_) <- map readInt . C.words <$> C.getLine
      return (x, y)
