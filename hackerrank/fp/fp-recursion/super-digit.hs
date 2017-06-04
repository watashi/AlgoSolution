import Data.Char

digitSum :: Integer -> Integer
digitSum = sum . map (`rem` 10) . takeWhile (>0) . iterate (`quot` 10)

main :: IO ()
main = do
  (n:k:_) <- fmap words getLine
  let s = toInteger (sum [ord i - ord '0' | i <- n]) * read k
  print $ until (<10) digitSum s