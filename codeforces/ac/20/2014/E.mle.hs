{-# LANGUAGE TupleSections #-}
import Control.Monad
import Data.Array
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as Map
import qualified Data.Set as Set
 
readInt :: ByteString -> Int
readInt = maybe (error "readInt") fst . C.readInt
 
readInts :: ByteString -> [Int]
readInts = map readInt . C.words
 
dijkstra :: Array Int [(Int, Int)] -> Int -> IntMap Int
dijkstra g start = go $ update start 0 (Set.empty, Map.empty)
  where
    update v d state@(pq, dist)
      | Just dd <- Map.lookup v dist
      , dd <= d = state
      | otherwise = (Set.insert (d, v) pq, Map.insert v d dist)
    go (pq0, dist) = case Set.minView pq0 of
      Nothing -> dist
      Just ((ds, s), pq)
        | dist Map.! s /= ds -> go (pq, dist)
        | otherwise -> go $ foldr (uncurry update) (pq, dist)
            [ (t, ds + w)
            | (t, w) <- g ! s
            ]
 
main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n: m: _h: _ <- readInts <$> C.getLine
    a <- readInts <$> C.getLine
    e <- fmap concat $ replicateM m $ do
      u: v: w: _ <- readInts <$> C.getLine
      return
        [ (u, (v, w))
        , (v, (u, w))
        , (n + u, (n + v, w `quot` 2))
        , (n + v, (n + u, w `quot` 2))
        ]
    let
      g = accumArray (flip (:)) [] (1, n + n) $ [(v, (n + v, 0)) | v <- a] ++ e
      ds = dijkstra g 1
      dt = dijkstra g n
      dst =
        [ max v w
        | (k0, v) <- Map.toList ds
        , let k = k0 `rem` n
        , Just w <- map (`Map.lookup` dt) [k, k + n]
        ]
    print $ if null dst then (-1) else minimum dst

-- 287145309	Oct/20/2024 20:29UTC-8	watashi	2014E - Rendez-vous de Marian et Robin	Haskell	Memory limit exceeded on test 6	2139 ms	262100 KB
