import Control.Monad
import Data.Array
import Data.Array.IO
import Data.Maybe

main :: IO ()
main = do
  [n, m] <- fmap (map read . words) getLine
  el <- replicateM m $ fmap (map read . words) getLine
  let e = accumArray (flip (:)) [] (1, n) $ concat [[(i, j), (j, i)] | [i, j] <- el]

  ans <- forM [1 .. n] $ \v -> do
    mark <- newArray (1, n) $ False :: IO (IOUArray Int Bool)
    d <- newArray (1, n) $ n :: IO (IOUArray Int Int)
    c <- newArray (1, n) $ 0 :: IO (IOUArray Int Double)
    s <- newArray (1, n) $ 0 :: IO (IOUArray Int Double)
    writeArray d 1 0
    writeArray c 1 1
    writeArray s 1 0

    forM_ [1 .. n] $ \_ -> do
      i <- liftM (snd . minimum . catMaybes) $ forM [1 .. n] $ \j -> do
        markj <- readArray mark j
        dj <- readArray d j
        if not markj
          then return $ Just (dj, j)
          else return Nothing

      writeArray mark i True
      di <- readArray d i
      ci <- readArray c i
      si <- readArray s i

      forM_ (e!i) $ \j -> do
        dj <- readArray d j
        case compare dj $ di + 1 of
          GT -> do
            writeArray d j $ di + 1
            writeArray c j $ ci
            writeArray s j $ si + if i == v || j == v then ci else 0
          EQ -> do
            cj <- readArray c j
            writeArray c j $ ci + cj
            sj <- readArray s j
            writeArray s j $ si + sj + if i == v || j == v then ci else 0
          LT -> return ()

    cn <- readArray c n
    sn <- readArray s n
    return $ sn / cn

  print $ maximum ans
