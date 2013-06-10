{--
m = 99

fsqrti = floor . sqrt . fromInteger

main = do print $ length $ [[a, b, c] |
								a <- [1 .. m],
								b <- [a .. m],
								c <- [b .. m],
								x <- [c],
								y <- [a + b],
								z <- [fsqrti $ x ^ 2 + y ^ 2],
								x ^ 2 + y ^ 2 == z ^ 2]
--}

-- x=r^2-s^2; y=2rs; z=r^2+s^2

import Data.Array
import Data.List

limit = 10000
rlimit = 150

pythagoras = [let x = r ^ 2 - s ^ 2; y = 2 * r * s in (min x y, max x y) | r <- takeWhile (<= rlimit) [1 ..], s <- [1 .. r - 1], odd (r + s) && gcd r s == 1]

todo = concat $ map (\(x, y) -> zip [x, x + x .. limit] [y, y + y .. limit]) $ pythagoras

gao = accumArray (+) 0 (0, limit) $ map (\(i, e) -> (i, succ e `div` 2)) $ concat [[(y, x - 1), (x, max 0 $ x + x - y + 1)] | (x, y) <- todo]

count = scanl1 (+) $ elems gao

main = do print $ length $ takeWhile (<= 1000000) count

