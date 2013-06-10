import System.Random
import Control.Monad

powMod a b m = powMod' b
	where
	powMod' 0 = 1 `mod` m
	powMod' n
		| even n	= p * p `mod` m
		| otherwise	= p * p * a `mod` m
		where p = powMod' (n `div` 2)

isPrime :: Int -> Integer -> IO Bool
isPrime k n
	| n < 2		= return False
	| n == 2	= return True
	| even n	= return False
	| otherwise	= do
		g <- getStdGen
		return $ foldl1 (&&) $ take k $ map gao $ take k $ randomRs (2, n') g
		where
			n' = pred n
			(s, d) = (\(a, b) -> (length a, head b)) $ span even $ iterate (`div` 2) n'
			itr = until (\(x, r) -> x == 1 || x == n' || r == s) (\(x, r) -> (x * x `mod` n, succ r))
			gao r = let x = powMod r d n in x == 1 || x == n' || (fst . itr) (x, 1) == n'

main = do
	todo <- sequence [filterM (isPrime 13) $ [m, m - n .. m - 3 * n] | n <- [2, 4 .. 32768], let m = (n + 1) ^ 2]
	putStrLn $ show $ (\x -> x * 2 + 3) $ length $ takeWhile (\(a, b) -> b * 10 >= a) $ tail $
		scanl (\(a, b) (c, d) -> (a + c, b + d)) (1, 0) $ zip (repeat 4) $ map length todo

