(&*) a = map (*a)
(.+) = zipWith (+)
(.-) = zipWith (-)
(.*) a = sum . zipWith (*) a
(#*) [x,y] [i,j] = x * j - y * i

side a b p = signum $ (b .- a) #* (p .- a)
same a b p q = side a b p * side a b q > 0
diff a b p q = side a b p * side a b q < 0
online a b p = side a b p == 0 && (a .- p) .* (b .- p) <= 0
block' a b p q = diff a b p q && not (same p q a b)
block a b p q = block' a b p q || online p q a || online p q b
mirror a b p = a .+ (r &* ab) .- ap where
	ab = b .- a
	ap = p .- a
	r = (2::Rational) * ab .* ap / ab .* ab
inter a b p q = a .+ ((ap #* pq / ab #* pq) &* ab) where
	ap = p .- a
	ab = b .- a
	pq = q .- p

gao [p,q,a,b,c,d] = let s = inter c d (mirror c d p) q in
	if block' c d p q then "NO"
	else if not (block a b p q) then "YES"
	else if not (same c d p q) then "NO"
	else if online c d s && not (block a b p s) && not (block a b s q) then "YES"
	else "NO"

main = do getContents >>= putStrLn . gao . take 6 . map (take 2) . iterate (drop 2) . map (fromIntegral . read) . words

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
234963 	Dec 29, 2010 5:39:09 PM 	watashi 	E - Hide-and-Seek 	Haskell 	Accepted 	30 ms 	1548 KB
-}
