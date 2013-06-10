import IO

main = do
	handle <- openFile "13in.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ take 10 $ show $ sum $ map read $ lines $ input
