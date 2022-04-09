import Control.Monad
import Data.Char
import Text.Printf

gao :: String -> String
gao "" = ""
gao (c:cs) = let x = gao cs in min (c:x) (c:c:x)

main :: IO ()
main = do
  re <- readLn :: IO Int
  forM_ [1 .. re] $ \ri -> do
    s <- filter isAsciiUpper <$> getLine
    printf "Case #%d: %s\n" ri $ gao s
