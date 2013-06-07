import Data.List

main :: IO ()
main = do
  _ <- getLine
  a <- fmap (map (read :: String -> Int) . words) getLine
  let (z,nz) = partition (==0) a
      (s,(h:t)) = partition (>0) nz
      (u,v) = splitAt (length t `div` 2 * 2) t
      i = [h]
      j = s ++ u
      k = z ++ v
  p i
  p j
  p k
  where
    p it = putStrLn $ unwords $ map show $ length it: it
