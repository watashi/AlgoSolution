import Data.Char (intToDigit)

main :: IO ()
main = do
  [a, b, n] <- fmap (map read . words) getLine
  let d = head $ filter (\i -> mod (a * 10 + i) b == 0) [0 .. 9] ++ [-1]
  if d == -1
    then putStrLn "-1"
    else putStrLn $ show a ++ [intToDigit d] ++ replicate (n - 1) '0'
