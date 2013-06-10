-- 2 6 12 20
-- 2 3 4 5 6 7 8 9 ....
-- T   T       T   ....

import Data.Ratio

main = do
	print $ (\x -> succ x * x) $ snd $ head $ filter (\(x, y) -> x < (1 % 12345)) $ zipWith (\x y -> (y % x, x)) [1 ..] $ scanl1 (+) [if until odd (`div` 2) i == 1 then 1 else 0 | i <- [2 ..]]

