import Control.Arrow ((***))
import Control.Monad (forM_, when)
import Control.Monad.ST (ST)
import Data.Array.ST (STUArray, runSTUArray, newArray, readArray, writeArray)
import Data.Array.Unboxed (UArray, assocs)
import Data.Int (Int64)

isqrt :: (Integral a, Integral b) => a -> b
isqrt = floor . sqrt . fromIntegral

threshold :: Integral a => a
threshold = fromIntegral threshold'
threshold' :: Int
threshold' = 1000000

primeList :: Integral a => [a]
primeList = map fromIntegral $ primeList'
primeList' :: [Int]
primeList' = primesToN threshold

-- primesToN
sieveToN :: Int -> UArray Int Bool
sieveToN n = runSTUArray sieve
  where
    sieve = do
      a <- newArray (2, n) True :: ST s (STUArray s Int Bool)
      forM_ [4, 6 .. n] $ \j ->
        writeArray a j False
      forM_ [3, 5 .. isqrt n] $ \i -> do
        ai <- readArray a i
        when ai $
          forM_ [i * i, i * (i + 2) .. n] $ \j ->
            writeArray a j False
      return a

primesToN :: (Integral a, Integral b) => a -> [b]
primesToN n = map (fromIntegral . fst) $ filter snd $ assocs $ sieveToN n'
  where
    n' = fromIntegral n

sieveFromMToN :: Int64 -> Int64 -> UArray Int64 Bool
sieveFromMToN m n = runSTUArray sieve
  where
    n' = isqrt n
    primes = if n' > threshold then primesToN n' else takeWhile (<=n') primeList
    sieve = do
      a <- newArray (m, n) True :: ST s (STUArray s Int64 Bool)
      forM_ primes $ \i -> do
        let s = max i $ div (m + i - 1) i
        when (i * s <= n) $
          forM_ [i * s, i * (s + 1) .. n] $ \j ->
            writeArray a j False
      return a

primesFromMToN :: (Integral a, Integral b) => a -> a -> [b]
primesFromMToN m n
  | m' <= n'  = map (fromIntegral . fst) $ filter snd $ assocs $ sieveFromMToN m' n'
  | otherwise = []
  where
    m' = fromIntegral $ max 2 m
    n' = fromIntegral n

gao a b c = if null ls then -1 else minimum $ zipWith max ls [b - a + 1, b - a ..]
  where
    primeList = primesFromMToN a b
    go [] _ = []
    go _ [] = []
    go x@(h:t) y@((p,q):r)
      | p < h     = go x r
      | otherwise = (h,q): go t y
    ls = scanl1 max [e - i + 1 | (i, e) <- go [a .. b] $ zip primeList $ drop (c-1) primeList]

main = do
  [a, b, c] <- fmap (map read . words) getLine
  print $ gao a b c
