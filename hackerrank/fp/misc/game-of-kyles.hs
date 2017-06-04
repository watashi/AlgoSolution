import Control.Monad
import Data.Bits
import Data.List

mex :: [Int] -> Int
mex s = go [0..] $ sort s
  where
  go (i:is) (j:js) | i == j = go is $ dropWhile (==j) js
  go i _ = head i

sg :: [Int]
sg = 0: map (mex . f) [1..]
  where
  f n = g (n - 1) ++ g (n - 2)
  g n = let t = take (n + 1) sg in zipWith xor t (reverse t)
  
main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    _ <- getLine
    s <- getLine
    let nim = foldl1' xor [sg !! length i | i@('I':_) <- group s]
    putStrLn $ if nim == 0 then "LOSE" else "WIN"