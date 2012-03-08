import Data.Char
import Data.List

main = putStrLn $ show $ sum $ map (digialSum . isqrt . (*10^198)) $ [1 .. 100] \\ [i ^ 2 | i <- [1 .. 10]]
digialSum = sum . map digitToInt . show
isqrt n = isqrt' 0 (n + 1)
	where isqrt' l r
		| l == r	= r - 1
		| otherwise	= let m = (l + r) `div` 2 in if m * m <= n then isqrt' (m + 1) r else isqrt' l m
