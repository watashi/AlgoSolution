import Data.Array

pentagonal :: [Integer]
pentagonal = scanl1 (+) $ scanl (+) 1 $ repeat 3

main :: IO ()
main = do
  re <- readLn
  q <- sequence $ replicate re readLn
  let p = listArray (1, maximum q) pentagonal
      ans = map (p!) q
  putStr $ unlines $ map show ans