import Control.Monad
import Data.Array
import Data.Int

main = do
	[n] <- getArray
	a <- replicateM (fromIntegral n) getArray
	[m] <- getArray
	b <- replicateM (fromIntegral m) getArray
	putStrLn $ unwords $ map show $ gao n b $ toArray a where
		toArray a = let n = fromIntegral $ length a in listArray ((1, 1), (n, n)) $ concat a
		getArray :: IO [Int32]
		getArray = fmap (map read . words) getLine
		gao :: Int32 -> [[Int32]] -> Array (Int32, Int32) Int32 -> [Int32]
		gao n [] _ = []
		gao n ([x,y,z]:bs) a = div (sum (map sum a')) 2 : gao n bs (toArray a') where
			a' = [[minimum [a!(i,j), a!(i,x) + z + a!(y,j), a!(i,y) + z + a!(x,j)] | j <- [1 .. n]] | i <- [1 .. n]]

--TLE10
