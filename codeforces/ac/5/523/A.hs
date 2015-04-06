import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
  (_:h:_) <- map read . words <$> getLine
  s <- replicateM h $ getLine
  forM_ (transpose s) $
    replicateM_ 2 . putStrLn . double
  where
  double [] = []
  double (h:t) = h:h:double t
