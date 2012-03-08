import Data.Array

decCycle d = decCycle' 0 1 (listArray (0, d - 1) (repeat $ -1))
	where decCycle' p r a
		| r == 0		= 0
		| a ! r == -1	= decCycle' (p + 1) (r * 10 `mod` d) (a // [(r, p)])
		| otherwise		= p - a ! r

main = do
	putStrLn $ show $ maximum $ map (\x -> (decCycle x, x)) $ [2 .. 999]
