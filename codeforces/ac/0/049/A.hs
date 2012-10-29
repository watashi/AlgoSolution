import Data.Char
main = do getLine >>= putStr . (\i -> if i then "YES" else "NO") . or . zipWith (==) "AEIOUY" . repeat . toUpper . last . filter isAlpha
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229535 	Dec 24, 2010 5:52:35 PM 	watashi 	A - Sleuth 	Haskell 	Accepted 	30 ms 	1540 KB
-}
