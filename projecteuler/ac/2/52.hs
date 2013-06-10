import Data.List (sort)
main = putStrLn $ show $ head $ dropWhile invalid $ [1 ..]
	where invalid x = invalid' 6
		where invalid' k
			| k == 2	= False
			| otherwise	= sort (show (k * x)) /= sort (show (2 * x)) || invalid' (k - 1)
-- 1/7: .(142857)
