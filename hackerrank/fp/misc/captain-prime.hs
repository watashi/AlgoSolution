import Control.Monad
import Data.List

isPrime :: Int -> Bool
isPrime 1 = False
isPrime n = [d | d <- takeWhile (\i -> i * i <= n) [1..], n `rem` d == 0] == [1]

isLeft, isRight :: String -> Bool
isLeft s = and $ notElem '0' s: [isPrime $ read i | i <- init $ tails s]
isRight s = and $ notElem '0' s: [isPrime $ read i | i <- tail $ inits s]

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    s <- getLine
    putStrLn $ case (isLeft s, isRight s) of
      (True, True) -> "CENTRAL"
      (True, False) -> "LEFT"
      (False, True) -> "RIGHT"
      (False, False) -> "DEAD"