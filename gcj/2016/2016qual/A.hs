import Control.Monad
import Data.Bits
import Data.List
import Text.Printf

digits :: Int -> [Int]
digits = map (`rem`10) . takeWhile (>0) . iterate (`quot`10)

gao :: Int -> Int
gao n = length . takeWhile (/=0) $
  scanl (\i j -> foldl' clearBit i $ digits j) allDigits [n, n + n ..]
  where
  allDigits = bit 10 - 1 :: Int

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- read <$> getLine
    printf "Case #%d: %s\n" ri (if n == 0 then "INSOMNIA" else show $ n * gao n)
