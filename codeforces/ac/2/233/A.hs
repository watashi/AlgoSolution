gao [] = []
gao (i:j:k) = j:i:gao k

main = do
  n <- fmap read getLine
  putStrLn $ unwords $ map show $ if odd n then [-1] else gao [1 .. n]

