import IO
import Data.Array

size = 80

toArray n = listArray (1, n)
toMatrix m n = toArray m . map (toArray n)

gao mat = dp ! size ! size
	where
		dp = toMatrix size size $ [[dp' (i, j) | j <- [1 .. size]] | i <- [1 .. size]]
		dp' (1, 1) = mat ! 1 ! 1
		dp' (i, 1) = dp ! (i - 1) ! 1 + mat ! i ! 1
		dp' (1, j) = dp ! 1 ! (j - 1) + mat ! 1 ! j
		dp' (i, j) = min (dp ! (i - 1) ! j) (dp ! i ! (j - 1)) + mat ! i ! j

main = do
	handle <- openFile "81matrix.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ gao $ toMatrix size size $ [read ("[" ++ line ++ "]") | line <- lines input]

