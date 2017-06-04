gao :: Int -> Int
gao n = length $ gen n []
  where
  test (x1, y1) (x2, y2) = and
    [ x1 /= x2
    , y1 /= y2
    , x1 + y1 /= x2 + y2
    , x1 - y1 /= x2 - y2
    , abs (x2 - x1) + abs (y2 - y1) /= 3
    ]
  gen 0 t = [t]
  gen x t = concat
    [ gen (x - 1) $ h: t
    | y <- [1..n]
    , let h = (x, y)
    , all (test h) t
    ]

main :: IO ()
main = do
  n <- readLn
  print $ gao n