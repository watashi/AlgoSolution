import Control.Arrow
import Control.Monad
import Data.List
import Data.Tuple

gao :: Int -> Int -> Maybe [(Int, Int)]
gao m n | m > n = map swap <$> gao n m
gao 1 _ = Nothing
gao 2 n = do
  guard $ n >= 5
  return $ concat [[(0, (i + 2) `rem` n), (1, i)] | i <- [0 .. n - 1]]
gao 3 n = do
  guard $ n >= 4
  return $ concat [[(0, i), (1, (i + 2) `rem` n), (2, i)] | i <- [0 .. n - 1]]
gao 4 4 = return [((i + 2 * j) `rem` 4, j) | i <- [3, 0, 1, 2], j <- [0 .. 3]]
gao m n
  | odd m = do
      up <- gao (m - 3) n
      down <- gao 3 n
      return $ up ++ map (first (+(m-3))) down
  | otherwise =
      fmap concat $ forM [0, 2 .. m - 2] $ \i -> map (first (+i)) <$> gao 2 n

_test :: Int -> Int -> Bool
_test m n = case gao m n of
  Nothing -> True
  Just ret ->
    all (\(i, j) -> 0 <= i && i < m && 0 <= j && j < n) ret &&
    length (group $ sort ret) == m * n &&
    and (zipWith t ret $ tail ret)
  where
  t (i, j) (i', j') = i /= i' && j /= j' && i + j /= i' + j' && i - j /= i' - j'

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    (m:n:_) <- map read . words <$> getLine
    putStr $ "Case #" ++ show ri ++ ": "
    case gao m n of
      Nothing -> putStrLn "IMPOSSIBLE"
      Just ans -> do
        putStrLn "POSSIBLE"
        mapM_ putStrLn [show (i + 1) ++ " " ++ show (j + 1) | (i ,j) <- ans]
