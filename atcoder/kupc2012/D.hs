import Data.List
import Control.Monad

getArray = fmap (map read . words) getLine

gao n m a
    | m > n     = 0
    | null x    = -n
    | otherwise = succ $ gao n z y
    where
        (x, y) = partition ((<=m) . head) a
        z = succ $ maximum $ map last x

main = do
    [n, m] <- getArray
    a <- replicateM m getArray
    putStrLn (let t = gao n 1 a in if t < 0 then "Impossible" else show t)
