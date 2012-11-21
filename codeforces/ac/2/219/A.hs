import Control.Applicative
import Data.List

main = do
  k <- fmap read getLine
  s <- fmap (map (liftA2 (,) length head) . group . sort) getLine
  if all (\(n, _) -> mod n k == 0) s
    then putStrLn $ concat $ replicate k $ concatMap (\(n, a) -> replicate (div n k) a) s
    else print $ -1
