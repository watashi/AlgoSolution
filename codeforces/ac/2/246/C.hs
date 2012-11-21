import Control.Arrow
import Control.Monad
import Data.Function
import Data.List

main = do
  [n, m] <- fmap (map read . words) getLine
  a <- fmap (sort . map read . words) getLine
  forM_ (foldl (gao (m + 1)) [(0, [])] a) $ \(_, i) ->
    when (not $ null i) $
      putStrLn $ unwords $ map show $ length i: i
  where
    gao n b a = take n $ map head $ groupBy ((==) `on` fst) $ sort $
      b ++ map ((a+) *** (a:)) b
