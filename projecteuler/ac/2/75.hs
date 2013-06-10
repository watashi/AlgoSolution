import Data.Array (accumArray, assocs)

-- x=r^2-s^2; y=2rs; z=r^2+s^2
limit = 1500000

todo = concat $ map (\x -> [x, x + x .. limit]) $ [2 * r * (r + s) | r <- takeWhile (< 1000) [1 ..], s <- [1 .. r - 1], odd (r + s) && gcd r s == 1]

unique' a = filter (\(_, c) -> c == 1) $ assocs $ accumArray (+) 0 (1, limit) [(i, 1) | i <- a]

main = do putStrLn $ show $ length $ unique' todo

