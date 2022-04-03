import Control.Monad
import Text.Printf

main :: IO ()
main = do
  re <- readLn :: IO Int
  forM_ [1..re] $ \ri -> do
    [r, c] <- fmap read . words <$> getLine
    let
      x = concat $ replicate (c - 1) "-+"
      y = concat $ replicate (c - 1) ".|"
    printf "Case #%d:\n..+%s\n..|%s\n+-+%s\n" ri x y x
    forM_ [2..r] $ \_ -> do
      printf "|.|%s\n+-+%s\n" y x
