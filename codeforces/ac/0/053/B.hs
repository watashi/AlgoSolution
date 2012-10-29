main = do
	[h, w] <- fmap (map read . words) getLine
	putStrLn $ unwords $ map show $ tail $ maximum $ (gao h w ++) $ map (\[a,b,c] -> [a,c,b]) $ gao w h
	where gao h w = [[x * y, x, y] | x <- takeWhile (<=h) $ iterate (*2) 1, 4 * x <= 5 * w, y <- [min w $ div (x * 5) 4]]
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
241428 	Jan 7, 2011 8:31:29 PM 	watashi 	53B - Blog Photo 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
