import List
main = do interact $ unwords . map show . (\i -> [maximum i, length i]) . map length . group . sort . map (read::String->Int) . tail . words
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235947 	Jan 2, 2011 3:02:28 PM 	watashi 	A - Towers 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
