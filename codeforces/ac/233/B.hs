import Data.Char

gao n = if null xs then -1 else head xs
  where
    xs = [x |
      s <- [1 .. 200],
      d <- [floor $ sqrt $ fromIntegral $ s * s + 4 * n],
      d * d == s * s + 4 * n,
      odd d == odd s,
      x <- [div (d - s) 2],
      (==s) $ sum $ map (toInteger . digitToInt) $ show x]

main = interact $ show . gao . read
