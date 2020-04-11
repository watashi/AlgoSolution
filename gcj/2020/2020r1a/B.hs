{-# LANGUAGE MagicHash #-}
import Control.Monad
import Data.Bits
import Data.List
import GHC.Integer.Logarithms
import GHC.Types
import Text.Printf

choose :: Integer -> Integer -> Integer
choose n k = foldl' (\i j -> i * (n + 1 - j) `quot` j) 1 [1 .. k]

walk :: [(Int, Int)] -> Integer
walk path = sum [choose (fromIntegral x - 1) (fromIntegral y - 1) | (x, y) <- path]

gao :: Integer -> [(Int, Int)]
gao n = gen (bitLimit + length bits + 1) bits (Left 0)
  where
  bitLimit = I# (integerLog2# n) + 1
  bits = filter (\i -> testBit (n - toInteger bitLimit) (i - 1)) [1 .. bitLimit]
  move (Left s) t = (Right t, [(i, 1) | i <- [s + 1 .. t - 1]])
  move (Right s) t = (Left t, [(i, i) | i <- [s + 1 .. t - 1]])
  gen end [] from = snd $ move from end
  gen end (b: bs) from = vmoves ++ hmoves ++ gen end bs to
    where
    (to, vmoves) = move from b
    hmoves = repeat b `zip` either (const id) (const reverse) from [1 .. b]

main :: IO ()
main = do
  re <- readLn
  forM_ [(1 :: Int) .. re] $ \ri -> do
    n <- readLn
    printf "Case #%d:\n" ri
    let ans = gao n
    -- print (length ans, walk ans)
    forM_ ans $ \(x ,y) -> printf "%d %d\n" x y
