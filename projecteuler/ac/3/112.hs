import Data.List (sort)

main = putStrLn $ show $ head $ dropWhile (\(n, m) -> n * 99 /= m * 100) $ zip [1 ..] $ scanl1 (+)
	[if j == k || j == reverse k then 0 else 1 | i <- [1 ..], let j = show i, let k = sort j]
