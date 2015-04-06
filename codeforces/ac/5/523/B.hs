import Control.Applicative
import Control.Monad
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

main :: IO ()
main = do
  (sn:st:sc:_) <- C.words <$> C.getLine
  let n = readInt sn
      t = readInt st
      c = read $ C.unpack sc
  a <- map readInt . C.words <$> C.getLine
  _m <- C.getLine
  p <- map readInt . C.words <$> C.getLine
  let x, y :: UArray Int Double
      a' = [fromIntegral i / fromIntegral t | i <- a]
      x = listArray (0, n) $ scanl (+) 0 a'
      y = listArray (0, n) $ scanl (\i j -> i / c + j) 0 a'
  forM_ p $ \i -> do
    let real = x!i - x!(i-t)
        approx = y!i / c
        err = abs (real - approx) / real
    putStrLn $ unwords $ map show [real, approx, err]
