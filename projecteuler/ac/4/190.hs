gao :: Double -> Double
gao n = product [(i * x) ** i | i <- [1 .. n]]
  where
    x = n / sum [1 .. n]

main :: IO ()
main = do
  let ans = sum [floor $ gao n | n <- [2 .. 15]] :: Integer
  print ans
