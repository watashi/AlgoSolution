main = do interact (unwords . map show . gao . map read . words)
gao [a, b] = if c >= 0 && even c {- && b .&. d == 0 -} then [d, a - d] else [-1] where
	c = a - b
	d = div c 2
-- a + b = 2 * (a and b) + (a xor b)
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
408685 	Apr 27, 2011 6:30:05 PM 	watashi 	76D - Plus and xor 	Haskell 	Accepted 	30 ms 	2000 KB 
-}
