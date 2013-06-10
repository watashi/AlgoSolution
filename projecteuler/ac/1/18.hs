-- copy 66.hs
import IO

main = do
	handle <- openFile "18in.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ gao $ lines input

gao [] = repeat 0
gao (x:xs) = zipWith max (zipWith (+) y z) (zipWith (+) y (tail z))
	where
		y = map read (words x)
		z = gao xs

