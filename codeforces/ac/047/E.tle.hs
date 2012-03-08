import Control.Monad
import Data.List
import Text.Printf

getArray :: Read a => IO [a]
getArray = fmap (map read . words) getLine

main = do
	[n, v] <- getArray
	a <- replicateM n getArray
	[m] <- getArray
	z <- replicateM m getArray
	putStrLn $ unlines $ map (unwords . (map $ printf "%.6f") . snd) $ sort $ gao n (fromIntegral v) (zip (map head a) [0 ..]) z

gao :: Int -> Double -> [(Double, Int)] -> [[Double]] -> [(Int, [Double])]
gao n v as zs = gao' (sort as) (sort zs) where
	eps = 1e-6
	g = 9.8
	gao' [] _ = []
	gao' ((a,i):a') z = (i, xy) : gao' a' z' where
		vx = v * cos(a)
		vy = v * sin(a)
		yt x = let t = x / vx in vy * t - g * t * t / 2
		z' = dropWhile (\[x, y] -> y < yt x + eps) z --WA
		xy = if null z' then [v * v * sin(2 * a) / g, 0] else let x = head $ head z' in [x, yt x] --WA
	
{- Time limit exceeded on test 7 -}
{- PS: if yt x < 0 .... WA -}
