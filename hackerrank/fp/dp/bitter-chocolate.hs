import Data.Array

dp :: Array (Int, Int, Int) Bool
dp = listArray ix $ map f $ range ix
  where
  ix = ((0, 0, 1), (25, 25, 25))
  f (0, 0, 1) = False
  f (a, b, c) = not . and $
    [dp ! (i, b, c) | i <- [0 .. a-1]] ++
    [dp ! (min a j, j, c) | j <- [0 .. b-1]] ++
    [dp ! (min a k, min b k, k) | k <- [1 .. c-1]]
    
main :: IO ()
main = do
  re <- readLn
  sequence_ . replicate re $ do
    (a:b:c:_) <- fmap (map read . words) getLine
    putStrLn $ if dp!(c, b, a) then "WIN" else "LOSE"