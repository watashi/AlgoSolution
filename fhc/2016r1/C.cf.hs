import Control.Applicative
import Control.Monad
import Data.Maybe
import Data.Ratio
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Integer, Integer, [Integer]) -> Double
solve (a, b, c) = fromRational $ sum (zipWith gao d $ tail d) % (b - a) / 2
  where
  d = scanl (+) 0 c
  z = last d
  gao x y
    | ai == bi = cost aj bj
    | otherwise = cost aj y + (bi - ai - 1) * cost x y + cost x bj
    where
    (ai, aj) = a `quotRem` z
    (bi, bj) = b `quotRem` z
    cost x' y'
      | lo < hi = (hi - lo) * (hi + lo - 2 * x)
      | otherwise = 0
      where
      lo = max x x'
      hi = min y y'

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    let getIntegers = map (toInteger . readInt) . C.words <$> C.getLine
    (_:a:b:_) <- getIntegers
    c <- getIntegers
    return (a, b, c)
