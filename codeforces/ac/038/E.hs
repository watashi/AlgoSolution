import Control.Monad
import Data.List
import Data.Int

getA = fmap (map read . words) getLine

gao [] = [0]
gao ([x,c]:r) = c + minimum (zipWith (+) d s) : s where
	s = gao r
	d = scanl (+) (0::Int64) $ map (subtract x . head) r

main = do
	[n] <- getA
	a <- replicateM (fromIntegral n) getA
	putStrLn $ show $ head $ gao $ sort a

{-
fromInteger: WA19
Int64: TLE40
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235843 	Jan 1, 2011 10:23:58 PM 	watashi 	E - Lets Go Rolling! 	Haskell 	Accepted 	1190 ms 	4628 KB
-}
