main :: IO ()
main = do
  a <- getLine
  b <- getLine
  let k = length $ takeWhile id $ zipWith (==) a b
      a' = drop k a
      b' = drop k b
      p s = putStrLn $ show (length s) ++ " " ++ s
  p $ take k a
  p $ drop k a
  p $ drop k b
  