import Control.Monad
import qualified Data.ByteString.Char8 as C
import Data.List
import Text.Printf

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    (n:_) <- readInts <$> C.getLine
    ys <- replicateM n $ do
      xs <- readInts <$> C.getLine
      return (minimum xs, maximum xs)
    let
      ans = (\f -> foldl' f [(0, 0)] ys) $ \pre (a, b) ->
        [ (i, minimum [d + abs (j - k) + abs (i - j) | (k, d) <- pre])
        | (i, j) <- [(a, b), (b, a)]
        ]
    printf "Case #%d: %d\n" ri $ minimum $ map snd ans
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
    readInts = map readInt . C.words
