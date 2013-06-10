main = putStrLn $ show $ maximum $ filter isPalindromic [x * y | x <- [100 .. 999], y <- [100 .. 999]]
	where isPalindromic x = s == reverse s where s = show x

