
palindromic n = s == reverse s
	where s = show n
lychrel n = lychrel' n 1
	where lychrel' n k = k < 50 && (palindromic n' || lychrel' n' (k + 1))
		where n' = n + (read . reverse . show) n
main = putStrLn $ show $ length $ filter (not . lychrel) [1 .. 9999]
