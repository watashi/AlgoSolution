import Data.List

main :: IO ()
main = do
  [_, m, k] <- fmap (map read . words) getLine
  a <- fmap (scanl (+) k . reverse . sort . map (pred . read) . words) getLine
  putStrLn $ maybe "-1" show $ findIndex (>=m) a
