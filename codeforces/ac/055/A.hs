import List

main = do
	n <- fmap read getLine
	putStrLn $ show' $ null $ ([0 .. n - 1]\\) $ take (n+n) $ map (`mod` n) $ scanl1 (+) [0 ..]

show' True = "YES"
show' False = "NO"
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
251376 	Jan 14, 2011 1:35:42 PM 	watashi 	A - Flea travel 	Haskell 	Accepted 	30 ms 	1552 KB
-}
