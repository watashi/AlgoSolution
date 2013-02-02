import Control.Monad
import Data.Int (Int64)

(+%) :: Int64 -> Int64 -> Int64
a +% b = if c >= m then c - m else c
  where
    c = a + b
    m = 4207849484

gao :: Int -> String -> [Int64]
gao _ "" = [1]
gao m s@(h:t) = foldl (+%) 0 [dp!!(i-1) | i <- [1 .. n], let j = read $ take i s, j <= m]: dp
  where
    dp = gao m t
    n
      | h == '0'        = 0
      | null $ drop 3 s = length s
      | otherwise       = 3

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    t <- fmap words getLine
    m <- return $ read $ head t
    a <- if length t > 1 then return $ last t else getLine
    let ans = head $ gao m a
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
