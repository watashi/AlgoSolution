main = do getLine >>= putStr . show . gao . map read . words

gao [n, m] = r1 + r2 + 2 * (i' - r') where
	r1 = min n ((m + 1) `div` 2)
	r2 = max 0 $ pred $ min n ((m + 4) `div` 4)
	r' = sum $ zipWith (-) [1 ..] $ tail $ scanl (\i j -> until ((>=j) . (^2)) succ i) 0 [i * i - m | i <- [1 .. n]]
	i' = sum $ map (min m) [i * i | i <- [1 .. n]]

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229476 	Dec 24, 2010 3:33:25 PM 	watashi 	E - Square Equation Roots 	Haskell 	Accepted 	4450 ms 	1548 KB 
-}
