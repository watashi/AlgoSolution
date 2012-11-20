import Control.Monad
import Data.Array.IO
import Data.Array.Unboxed

main = do
  n <- fmap read getLine
  x <- fmap (map read . words) getLine
  y <- newArray_ (1, n) :: IO (IOUArray Int Int)
  z <- newArray (1, n) 0 :: IO (IOUArray Int Int)
  forM_ (zip [1 .. n] x) $ \(i, e) ->
    writeArray y i e
  forM_ (reverse [1 .. n]) $ \i -> do
    l <- index y $ i * 2
    r <- index y $ i * 2 + 1
    m <- index y i
    writeArray z i $ max l r
    writeArray y i $ max 0 $ m - max l r
  h <- index y 1
  t <- getElems z

  if n >= 3 && odd n
    then print $ sum $ h:t
    else print $ -1
  where
    index :: IOUArray Int Int -> Int -> IO Int
    index a i = do
      bounds <- getBounds a
      if inRange bounds i
        then readArray a i
        else return 0
