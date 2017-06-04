import qualified Data.IntMap.Strict as Map

main :: IO ()
main = do
  let getInts = fmap (map read . words) getLine
  _ <- getLine
  a <- getInts
  _ <- getLine
  b <- getInts
  let c = Map.fromListWith (+) $ a `zip` repeat (-1) ++ b `zip` repeat 1
      ans = Map.keys $ Map.filter (>0) c
  putStrLn $ unwords $ map show ans