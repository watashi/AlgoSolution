import Control.Monad
import Control.Monad.ST
import Data.Array.IArray
import Data.Array.MArray
import Data.Array.ST
import Data.Array.Unboxed

isqrt = floor . sqrt . fromIntegral

primeToNA :: Int -> UArray Int Bool
primeToNA n = runSTUArray sieve where
	sieve = do
		a <- newArray (2, n) True :: ST s (STUArray s Int Bool)
		let sr = isqrt n
		forM_ [4, 6 .. n] $ \j -> writeArray a j False
		forM_ [3, 5 .. sr] $ \i -> do
			si <- readArray a i
			when si $
				forM_ [i * i, i * (i + 2) .. n] $ \j -> writeArray a j False
		return a

primesToN :: Int -> [Int]
primesToN n = [i | (i, e) <- assocs . primeToNA $ n, e]


main = do
	putStrLn $ show $ sum $ [bs (n `div` q) - i | (i, q) <- zip [0 ..] $ takeWhile (<= isqrt n) p] where
		n = 100000000
		p = primesToN n
		c = length $ p
		bs v = bs' 0 c where
			bs' l r
				| l == r		= r
				| p !! m <= v	= bs' (succ m) r
				| otherwise		= bs' l m
				where m = div (l + r) 2

{-
17427258

real	0m41.941s
user	0m41.359s
sys	0m0.476s
-}
