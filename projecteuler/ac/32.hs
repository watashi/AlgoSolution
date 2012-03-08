import Data.Set (fromList, toList)
import Data.List (sort)

main = putStrLn $ show $ sum $ toList $ fromList $ map (uncurry (*)) $ filter unusual todo
	where
		todo = [(a, b) | a <- [1 .. 100], b <- [a .. 10000]]
		unusual (a, b) = sort (show a ++ show b ++ show (a * b)) == "123456789"

