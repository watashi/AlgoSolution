import Control.Monad
import qualified Data.ByteString.Char8 as C
import Data.List
import Text.Printf

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1..re] $ \ri -> do
    _ <- C.getLine
    ds <- fmap readInt . C.words <$> C.getLine
    printf "Case #%d: %d\n" ri $ go 0 $ sort ds
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
    go n x = case dropWhile (<=n) x of
      [] -> n
      (_:y) -> go (n + 1) y
