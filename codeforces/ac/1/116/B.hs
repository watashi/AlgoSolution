import Control.Monad
import Control.Arrow

main = do
    [r, c] <- fmap (map read . words) getLine
    a <- replicateM r getLine
    print $ length $ [[i, j] |
        i <- [0 .. r - 1], j <- [0 .. c - 1], a!!i!!j == 'W',
        any id [0 <= x && x < r && 0 <= y && y < c && a!!x!!y == 'P' |
            k <- [id *** pred, id *** succ, pred *** id, succ *** id], (x, y) <- [k (i, j)]]]

-- # 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
-- 735699 	Oct 3, 2011 3:22:38 PM 	watashi 	116B - Little Pigs and Wolves 	Haskell 	Accepted 	30 ms 	2000 KB 
