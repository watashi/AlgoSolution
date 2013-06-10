{-
gao :: Int -> [Int]
gao n = gao' n
	where
		gao' 1 = take (n + 1) $ repeat 1
		gao' i = b
			where
				a = gao' $ pred i
				b = [(a !! j + if j < i then 0 else b !! (j - i)) `mod` 1000000 | j <- [0 .. n]]
-}

{-
 - http://www.research.att.com/~njas/sequences/A000041
a(n) - a(n-1) - a(n-2) + a(n-5) + a(n-7) - a(n-12) - a(n-15) + ... = 0, where the sum is over n-k and k is a generalized pentagonal number (A001318) <= n and the sign of the k-th term is (-1)^([(k+1)/2]). See A001318  for a good way to remember this! 
-}

-- http://en.wikipedia.org/wiki/Partition_%28number_theory%29

import Data.Array

limit = 100000

pentagonal = zip (cycle [1, 1, -1, -1]) $ takeWhile (< limit) $ map (\i -> i * (3 * i - 1) `div` 2) $ concat [[i, -i] | i <- [1 ..]]

partitions = listArray (0, limit) a
	where
		a = 1 : [partitions' i | i <- [1 .. limit]]
		partitions' i = sum [f * partitions ! (i - s) | (f, s) <- takeWhile ((<= i) . snd) pentagonal] `mod` 1000000

main = do putStrLn $ show $ head $ filter (\(_, x) -> x == 0) $ assocs partitions

