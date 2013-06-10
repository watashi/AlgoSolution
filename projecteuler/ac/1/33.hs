import Data.List
import Data.Ratio

ok (a, b) = foldr1 (||) [b /= b' && b' /= 0 && a * b' == a' * b |
	d <- "123456789", let a' = read $ sa \\ [d], let b' = read $ sb \\ [d]]
	where sa = show a; sb = show b

main = let f = [(a, b) | let c = [10 .. 99] \\ [11, 22 .. 99], a <- c, b <- c, a < b] in
	putStrLn $ show $ denominator $ product $ map (\(a, b) -> a % b) $ filter ok f

