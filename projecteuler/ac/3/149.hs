import Control.Arrow
import Data.Array.Unboxed

sample :: UArray (Int, Int) Int
sample = listArray ((1, 1), (4, 4)) $ concat [
    [-2, 5, 3, 2],
    [9, -6, 5, 1],
    [3, 2, 7, 3],
    [-1, 8, -4, 8]]

table :: UArray (Int, Int) Int
table = listArray ((1, 1), (2000, 2000)) al
  where
    m = 1000000
    f k = ((300007 * k * k - 200003) `rem` m * k + 100003) `rem` m - 500000
    g (i:it) (j:jt) = (i + j + m) `rem` m - 500000: g it jt
    g _ _ = undefined
    al = [f k | k <- [1 .. 55]] ++ g (drop 31 al) al

gao :: UArray (Int, Int) Int -> Int
gao a = maximum [maxsum $ map (a!) ix |
    (x, y) <- indices a,
    (dx, dy) <- [(0, 1), (1, 0), (1, 1), (1, -1)],
    not $ valid (x - dx, y - dy),
    let ix = takeWhile valid $ iterate ((+dx) *** (+dy)) (x, y)]
  where
    valid = inRange (bounds a)
    maxsum = maximum . scanl (\i j -> max 0 $ i + j) 0

main :: IO ()
main = print $ gao $ table
