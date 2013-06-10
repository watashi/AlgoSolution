import Control.Monad
import Control.Monad.ST
import Data.Array.IArray
import Data.Array.MArray
import Data.Array.ST
import Data.Array.Unboxed
import Data.List
import Data.Ratio

phiToNA :: Int -> UArray Int Int
phiToNA n = runSTUArray sieve where
	sieve = do
		a <- newListArray (2, n) [2 ..] :: ST s (STUArray s Int Int)
		forM_ [2 .. n] $ \i -> do
			ai <- readArray a i
			when (ai == i) $
				forM_ [i, i + i .. n] $ \j -> do
					aj <- readArray a j
					writeArray a j $ aj `div` i * pred i
		return a

main = do
	putStrLn $ show $ foldr1 min $ [(toInteger n % toInteger phi, n) | (n, phi) <- assocs $ phiToNA $ 10000000, show n \\ show phi == []]
