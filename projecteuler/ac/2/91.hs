z = 50
z' = sum [let g = gcd x y; a = div y g; b = div x g in min (div x a) (div (z - y) b) | x <- [1 .. z], y <- [1 .. z]]
main = do putStrLn $ show $ 3 * z * z + 2 * z'
