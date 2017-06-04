import qualified Data.Map.Strict as Map

gao :: [Int] -> Int
gao = go dp0 . map ((`mod` 10) . pred)
  where
  dp0 = Map.fromList [((i, j), 0) | i <- [0 .. 9], j <- [0 .. 9]]
  go dp [] = minimum $ Map.elems dp
  go dp (d: ds) = flip go ds $ Map.fromListWith min $ concat
    [ [ ((d, j), e + abs (d - i) + 1)
      , ((i, d), e + abs (d - j) + 1)
      ]
    | ((i, j), e) <- Map.assocs dp
    ]
    
main :: IO ()
main = do
  _ <- getLine
  a <- fmap (map read . words) getLine
  print $ gao a