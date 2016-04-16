import Data.Char
import Control.Monad

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    s <- filter isUpper <$> getLine
    let ans = gao (head s) [] [] s
    putStrLn $ "Case #" ++ show ri ++ ": " ++ ans
  where
  gao _ prefix suffix [] = prefix ++ reverse suffix
  gao m prefix suffix (c:s)
    | c >= m = gao c (c:prefix) suffix s
    | otherwise = gao m prefix (c:suffix) s
