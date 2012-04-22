import Control.Monad
import Data.Bits

main = do
    [r, c] <- fmap (map read . words) getLine
    a <- replicateM r getLine
    let b = [(i, j) | i <- [1 .. r], j <- [1 .. c], a!!(i-1)!!(j-1) == '*']
        f g = show $ foldl1 xor $ map g b
        in putStrLn $ unwords $ [f fst, f snd]
