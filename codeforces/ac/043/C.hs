import Data.Array (accumArray, (!))

main = do
	dummy <- getLine
	a <- getLine
	let a' = accumArray (+) 0 (0, 2) $ map (\x -> (mod x 3, 1)) $ map read $ words $ a in
		putStrLn $ show $ div (a'!0) 2 + min (a'!1) (a'!2)

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
208973 	Dec 6, 2010 12:08:38 PM 	watashi 	C - Lucky Tickets 	Haskell 	Accepted 	90 ms 	3604 KB
-}
