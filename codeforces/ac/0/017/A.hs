p = s [2 ..]
s (p:q) = (p:) $ s $ filter ((/=0) . (`mod` p)) $ q
r = filter (\i -> let (a,b:_) = break (> div i 2) p in not (null a) && last a + b + 1 == i) p
main = do
	[n, k] <- fmap (map read . words) getLine
	putStrLn $ if length (takeWhile (<= n) r) >= k then "YES" else "NO"
--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--284130 	Feb 13, 2011 6:37:11 PM 	watashi 	17A - Noldbach problem 	Haskell 	Accepted 	30 ms 	1600 KB
