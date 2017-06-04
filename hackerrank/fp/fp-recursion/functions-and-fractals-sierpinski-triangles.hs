sz :: Int
sz = 32

gao :: Int -> Int -> Int -> Int -> Char
gao 0 s x y = if abs (y - s) <= x - 1 then '1' else '_'
gao n s x y
  | x <= m = gao (n-1) m x (y-m)
  | otherwise = gao (n-1) m (x-m) (if y <= s then y else y - s)
  where
  m = s `quot` 2
  
main :: IO ()
main = do
  n <- readLn
  putStr $ unlines [[gao n sz x y | y <- [1 .. sz * 2 - 1]] | x <- [1 .. sz]]