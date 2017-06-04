gao :: Int -> Int -> Int -> Int -> Char
gao n u x y
  | n <= 0 = '_'
  | x <= u = if y == 0 then '1' else '_'
  | x <= 2 * u = if abs y == x - u then '1' else '_'
  | otherwise = gao (n - 1) (u `quot` 2) (x - 2 * u) (abs y - u)

main :: IO ()
main = do
  n <- readLn
  putStrLn $ unlines [[gao n 16 x y | y <- [-49 .. 50]] | x <- [63, 62 .. 1]]