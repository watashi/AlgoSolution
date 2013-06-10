import IO
import Data.Char(ord)
import Data.List(sort)

main = do
	names <- getNames
	putStrLn $ show $ sum $ map (uncurry (*)) $ zip (map worth $ sort names) [1 ..]

worth = sum . map (\x -> ord x - ord 'A' + 1)

getNames = do	
	handle <- openFile "22names.txt" ReadMode
	input <- hGetContents handle
	return $ read ("[" ++ input ++ "]")

