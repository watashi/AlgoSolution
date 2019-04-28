import Control.Applicative ((<$>))
import Control.Monad (forM_, liftM2)
import Data.Array
import Data.Tuple (swap)

type Board = Array (Int, Int) Char

toBoard :: Int -> Int -> [Char] -> Board
toBoard r c = listArray ((1,1), (r,c))

gao :: Int -> Int -> Int -> Maybe Board
gao r c m | r > c = ixmap ((1,1), (r,c)) swap <$> gao c r m
gao r c 1 = Just . toBoard r c $ repeat '*'
gao 1 c m = Just . toBoard 1 c $ replicate m '.' ++ repeat '*'
gao 2 c m
  | m >= 4 && even m = toBoard 2 c . cycle . elems <$> gao 1 c (m `quot` 2)
  | otherwise = Nothing
gao r c m
  | m < 4 || (m < 9 && odd m) = Nothing
  | length topLeftCells < m = Just . complement . take m $
      topLeftCells ++ bottomRightCells
  | otherwise = Just . complement . (if odd m then ((3, 3):) else id) $
      take (m `quot` 2 * 2) topLeftCells
  where
  complement cells = toBoard r c (repeat '*') // [(i, '.') | i <- cells]
  topLeftCells = concat $
    [(1, 1), (1, 2), (2, 1), (2, 2)]:
    [[(i, 1), (i, 2), (1, i), (2, i)] | i <- [3 .. r]] ++
    [[(1, i), (2, i)] | i <- [r + 1 .. c]]
  bottomRightCells = liftM2 (,) [3..r] [3..c]

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    [r, c, m] <- map read . words <$> getLine
    putStrLn $ "Case #" ++ show ri ++ ":"
    case gao r c $ r * c - m of
      Just ans -> do
        let chr 1 1 = 'c'
            chr i j = ans ! (i, j)
            ans' = [[chr i j | j <- [1..c]] | i <- [1..r]]
        putStr $ unlines ans'
      Nothing -> putStrLn "Impossible"

