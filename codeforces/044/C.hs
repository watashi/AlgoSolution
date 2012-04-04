import Control.Monad
import Data.Array
import Data.List

getA = fmap (map read . words) getLine

main = do
	[n, m] <- getA
	a <- replicateM m getA
	putStrLn $ toS $ find ((/=1) . snd) $ assocs $ accumArray (+) 0 (1, n) $ concat $ map (\[i, j] -> zip [i .. j] $ repeat 1) a where
		toS Nothing = "OK"
		toS (Just (i, j)) = show i ++ " " ++ show j
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
404502 	Apr 21, 2011 2:35:30 PM 	watashi 	44C - Holidays 	Haskell 	Accepted 	30 ms 	2000 KB
-}
