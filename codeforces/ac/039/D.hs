main = do interact (gao . read)
gao n = if a!!y /= m then "NO" else unlines $ "YES": map show c where
	a = let f i j = i: f j (13 * j - 12 * i) in f 2 13
	x = last $ takeWhile ((==0) . mod n . (12^)) [0 ..]
	m = div n (12 ^ x)
	y = head $ dropWhile ((<m) . (a!!)) [0 ..]
	z = 2 * x + y
	b = [a!!(z - 2 * i) * 12 ^ i | i <- reverse [0 .. div z 2], i /= x]
	c = 1: toInteger z + 1: toInteger (length b): b
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235808 	Jan 1, 2011 6:14:13 PM 	watashi 	D - Interesting Sequence 	Haskell 	Accepted 	50 ms 	1548 KB 
-}
