import Control.Monad
import Data.Array
import qualified Data.ByteString.Char8 as C
import Text.Printf

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1..re] $ \ri -> do
    n <- readInt <$> C.getLine
    f <- listArray (1, n) <$> readInts
    p <- readInts
    let
      c = accumArray (flip (:)) [] (0, n) $ zip p [1..]
      dfs v
        | null ws = (fv, fv)
        | m > fv = (s, m)
        | otherwise = (s - m + fv, fv)
        where
          fv = f!v
          ws = c!v
          (ss, ms) = unzip $ map dfs ws
          s = sum ss
          m = minimum ms
      ans = sum $ map (fst . dfs) $ c!0
    printf "Case #%d: %d\n" ri ans
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
    readInts = fmap readInt . C.words <$> C.getLine
