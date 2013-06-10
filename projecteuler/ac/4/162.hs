import Text.Printf

main = do printf "%X\n" $ (sum $ [sum $ cc i | i <- [1 .. 16]] :: Integer) where
	cc n = [c (pred n) i * c (n - i) (j - i) * c (n - j) (k - j) * 13 ^ (n - k) | i <- [1 .. n], j <- [i + 1 .. n], k <- [j + 1 .. n]]
	c n m = foldl (\a b -> a * (succ n - b) `div` b) 1 [1 .. m]

