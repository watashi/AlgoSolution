import Data.Bits

main :: IO ()
main = do
  [n, m] <- fmap (map read . words) getLine
  let ans = [take n $ (0:) $ cycle $ replicate b 0 ++ replicate b b |
        b <- map (2^) [0 .. m - 1]]
  putStr $ unlines $ [unwords $ reverse $ map (show . (n-)) i | i <- ans]
