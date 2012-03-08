import IO

main = do
	handle <- openFile "99base_exp.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ maximum $ zip (values input) [1 ..]
	where values = map (\l -> (\(a, b) -> b * log a) $ read $ ("(" ++ l ++ ")")) . lines

-- 709

