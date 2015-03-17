import Control.Applicative
import Data.Char
import Data.Map hiding (map)

main :: IO ()
main = do
  n <- read <$> getLine
  m <- go n $ singleton "polycarp" 1
  print $ maximum $ elems m
  where
  key = map toLower
  go 0 m = return m
  go i m = do
    [a, _, b] <- words <$> getLine
    go (i-1) $ insert (key a) (m!key b + 1) m
