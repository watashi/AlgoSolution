-- n ^ 2n ^ 3n = 0 => n & (n << 1) = 0

zero = 0: [zero' i | i <- [1 .. ]]
one = 0: [one' i | i <- [1 .. ]]

zero' 1 = 1
zero' n = zero !! (n - 1) + one !! (n - 1)

one' 1 = 1
one' n = zero !! (n - 1)

main = putStrLn $ show $ zero' 30 + one' 30

-- 2178309
