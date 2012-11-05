{-# OPTIONS_GHC -O2 -optc-O3 -fignore-asserts #-}
import Control.Monad
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main = do
  [n] <- getArray
  a <- replicateM n getArray
  [m] <- getArray
  b <- replicateM m getArray
  putStrLn $ unwords $ map (show . (`div` 2)) $ gao n b $ concat a
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
    gao n [] _ = []
    gao n ([x,y,z]:bs) a = sum a': gao n bs a'
      where
        x' = x - 1
        y' = y - 1
        a' = if z < a!!(x' * n + y') then zipWith min a $! d else a
        d = zipWith (\i j -> z + min i j) [i + j | i <- u, j <- v] [i + j | i <- v, j <- u]
          where
            u = take n $ drop (x' * n) a
            v = take n $ drop (y' * n) a

-- TLE10
-- TLE12
