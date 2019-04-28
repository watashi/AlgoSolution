import Control.Monad
import Data.List

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    r1 <- getRow
    r2 <- getRow
    putStr $ "Case #" ++ show ri ++ ": "
    case r1 `intersect` r2 of
      []  -> putStrLn "Volunteer cheated!"
      [x] -> print x
      _   -> putStrLn "Bad magician!"
  where
  getRow :: IO [Int]
  getRow = do
    answer <- fmap read getLine
    arrangement <- replicateM 4 $ fmap (map read . words) getLine
    return $ arrangement !! pred answer
