import List

main = do
	n <- fmap read getLine
	a <- fmap (map read . words) getLine
	putStrLn $ show $ gao n a

gao :: Int -> [Integer] -> Integer
gao n a = if null o then 0 else sum e + sum (if odd $ length o then o else tail o) where
	o = sort $ filter odd a
	e = sort $ filter even a
