import System.Random
import Control.Monad
import Data.List (inits, delete)

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

permutations [] = [0]
permutations a = concat [map ((+ai) . (*10)) $ permutations $ delete ai a | ai <- a]

main = do
	-- sum [1 .. 8] = 36 mod 3 = 0, sum [1 .. 9] = 45 mod 3 = 0, not prime
	todo <- filterM (isPrime 10) $ concat $ map permutations $ tail $ inits $ [1 .. 7]
	putStrLn $ show $ maximum $ todo
