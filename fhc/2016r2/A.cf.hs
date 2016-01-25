import Control.Applicative
import Control.Monad
import Data.Array
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Int, C.ByteString, C.ByteString) -> Int
solve (n, a, b) = minimum
  [ max (cl!left) (cr!(n-right))
  | (left, right) <- assocs same
  ]
  where
  cost s = listArray (0, n) . scanl1 (+) $
    [0, 1] ++ C.zipWith (\i j -> if i == j then 0 else 1) s (C.tail s)
  cl = cost b
  cr = cost $ C.reverse b
  same = listArray (0, n) $
    [ if a `C.index` i == b `C.index` i then same!(i+1) else i
    | i <- [0 .. n - 1]
    ] ++ [n]

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    n <- readInt <$> C.getLine
    a <- C.take n <$> C.getLine
    b <- C.take n <$> C.getLine
    return (n, a, b)
