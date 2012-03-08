import IO
import Data.Char

main = do
	handle <- openFile "42words.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ length $ filter (triangle . value) $ read ("[" ++ input ++ "]")
	where
		value = sum . map (\x -> ord x - ord 'A' + 1)
		triangle x = head (dropWhile (<x) [n * (n + 1) `div` 2 | n <- [1 ..]]) == x

