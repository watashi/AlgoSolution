chk [] _ = True
chk (p:ps) x = x `mod` 10 == p && chk ps (x `div` 100)

gao p x = filter (\x -> chk (take p [9, 8 ..]) (x * x)) [i * 100 ^ (p - 1) + j | i <- [0 .. 99], j <- x]

main = putStrLn $ show $ map (*10) $ filter (\x -> chk [9, 8 .. 1] (x * x)) $ todo
	where todo = concat [[i, 10^8 + i] | i <- gao 4 $ gao 3 $ gao 2 $ gao 1 [0]]
