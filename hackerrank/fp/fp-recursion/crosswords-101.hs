import Control.Monad
import Data.Function
import Data.List
import qualified Data.Map.Strict as Map
import Data.Monoid
import Data.Tuple

type Grid = Map.Map (Int, Int) Char

update :: [((Int, Int), Char)] -> Grid -> Maybe Grid
update a b = foldr (\i j -> go i =<< j) (Just b) a
  where
  go (k, v) m
    | c == '-' = Just $ Map.insert k v m
    | c == v = Just m
    | otherwise = Nothing
    where
    c = m Map.! k

blanks :: [String] -> [[(Int, Int)]]
blanks s = go s ++ map (map swap) (go $ transpose s)
  where
  go t =
    [ repeat i `zip` map fst j
    | (i, r) <- zip [0..] t
    , j@((_, '-'): _: _) <- groupBy ((==) `on` snd) $ zip [0..] r
    ]

gao :: [[(Int, Int)]] -> [String] -> Grid -> Maybe Grid
gao [] _ m = Just m
gao _ [] m = Just m
gao (b: bs) candidates m = getFirst $ mconcat
  [ First $ gao bs' (l ++ r) m'
  | (l, c: r) <- inits candidates `zip` tails candidates
  , length b == length c
  , Just m' <- [update (b `zip` c) m]
  ]
  where
  bs' = let (i, j) = partition (not . null . intersect b) bs in i ++ j

main :: IO ()
main = do
  let n = 10
  m <- replicateM n getLine
  candidates <- fmap (words . map (\c -> if c == ';' then ' ' else c)) getLine
  let grid = Map.fromList
        [ ((i, j), c)
        | (i, r) <- zip [0..] m
        , (j, c) <- zip [0..] r
        ]
  case gao (blanks m) candidates grid of
    Just ans -> putStr $ unlines
      [ [ans Map.! (i, j)  | j <- take n [0..]]
      | i <- take n [0..]
      ]
    Nothing -> error "IMPOSSIBLE"
