import Control.Monad
import Control.Monad.ST
-- import Data.Array (listArray, (!))
import Data.Array.ST
import Data.Array.Unboxed
-- hiding (listArray, (!))

eulerTotientsToN :: Int -> UArray Int Int
eulerTotientsToN n = runSTUArray gao
  where
    gao = do
      a <- newArray (1, n) 0 :: ST s (STUArray s Int Int)
      forM_ [1 .. n] $ \i ->
        writeArray a i i
      forM_ (2:[3, 5 .. floor $ sqrt $ fromIntegral n]) $ \i -> do
        ai <- readArray a i
        when (ai == i) $
          forM_ [i * i, i * (i + 1) .. n] $ \j ->
            writeArray a j i
      forM_ [1 .. n] $ \i -> do
        ai <- readArray a i
        let j = i `div` ai
        aj <- readArray a j
        writeArray a i $ aj * if mod j ai == 0 then ai else ai - 1
      return a

(n, m) = (40000000, 25)

{-
eulerTotients = listArray (1, n) $ elems $ eulerTotientsToN n

chainLength = listArray (1, n) $ 1:[succ $ (chainLength!) $ (eulerTotients!) $ i | i <- [2 ..]]

main = print $ [i | i <- [2 .. n], eulerTotients!i == i - 1, chainLength!i == m]

./214  22.50s user 3.23s system 6% cpu 7:08.03 total
-}

eulerTotients = eulerTotientsToN n

chain 1 = [1]
chain n = n: chain (eulerTotients!n)

main = print $ sum $ map toInteger ans
  where
    ans = [i | i <- [2 .. n], eulerTotients!i == i - 1, (==m) $ length $ take (m + 1) $ chain i]

-- ./214  9.10s user 0.28s system 99% cpu 9.451 total

