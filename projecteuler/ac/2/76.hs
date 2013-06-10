import IO
import Data.Array

toArray n = listArray (0, n)
toMatrix m n = toArray m . map (toArray n)

count n = dp ! n
	where
		dp = toMatrix n n $ [[dp' (i, j) | j <- [0 .. n]] | i <- [0 .. n]]
		dp' (0, 0) = 1
		dp' (0, _) = 0
		dp' (m, s) = dp ! (m - 1) ! s + if m > s then 0 else dp ! m ! (s - m)

main = putStrLn $ show $ count 100 ! 100 - 1

