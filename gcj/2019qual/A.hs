import Control.Monad
import Data.Char
import Text.Printf

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    s <- getLine
    let (a, b) = unzip
          [ if c == '4' then ('3', '1') else (c, '0')
          | c <- s
          , isDigit c
          ]
    printf "Case #%d: %s %s\n" ri a $ dropWhile (== '0') b
