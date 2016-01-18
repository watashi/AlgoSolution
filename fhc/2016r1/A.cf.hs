import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: [Int] -> Int
solve d = head . fst $ foldl' gao ([0], []) d
  where
  gao (dp, xs) x = (dp', xs')
    where
    xs' = x: xs
    dp' = minimum [u + w | (u, v, w) <- zip3 dp gapsum [3, 2, 1, 0], v <= w]: dp
    gapsum = scanl (+) 0 $ catMaybes $ takeWhile isJust $ zipWith gap xs xs'
    gap i j
      | i < j = Just $ (j - i - 1) `quot` 10
      | otherwise = Nothing

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    _ <- C.getLine
    map readInt . C.words <$> C.getLine
