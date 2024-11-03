{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE MultiWayIf #-}
import Control.Monad
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C

readInt :: ByteString -> Int
readInt bs = let Just (i, _) = C.readInt bs in i

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

gao :: Int -> Int -> [(Int, Int)] -> Int
gao m k = go 0 0 []
  where
    go !result !ts !before !after = if
      | x@(d, _): xs <- after
      , d == ts -> go result ts (x: before) xs
      | [] <- before -> case after of
          [] -> result
          (d, _): _ -> go result d [] after
      | (d, a): xs <- before -> if
        | d <= ts - k -> go result ts [] after
        | a <= m
        , (ok, ys) <- go1 ts m before -> go (result + ok) (ts + 1) ys after
        | ok <- min (min (a `quot` m) (d + k - ts)) $ case after of
            [] -> maxBound
            (dd, _): _ -> dd - ts
        , ys <- (d, a - ok * m): xs -> go (result + ok) (ts + ok) ys after
    go1 !ts !rest !before
      | rest == 0 = (1, before)
      | [] <- before = (0, [])
      | (d, a): xs <- before = if
        | d <= ts - k -> go1 ts rest []
        | a <= rest -> go1 ts (rest - a) xs
        | otherwise -> go1 ts 0 $ (d, a - rest): xs

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n: m: k: _ <- readInts <$> C.getLine
    list <- replicateM n $ do
      d: a: _ <- readInts <$> C.getLine
      return (d, a)
    print $ gao m k list

-- 286657161	Oct/19/2024 00:19UTC-7	watashi	2014G - Milky Days	Haskell	Accepted	296 ms	36900 KB
