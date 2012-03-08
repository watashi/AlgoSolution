import Primes (primesToN)

main = do
	putStrLn $ show $ head $ dropWhile ((<= 10 ^ 10) . snd) $ [(n, 2 * n `mod` p * p) | (n, p) <- zip [1 .. ] $ map toInteger $ primesToN 1000000, odd n]

