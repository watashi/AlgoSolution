import Primes

n = 20000000
m = 15000000

primeList = primesToN n

factExponent n p = sum $ takeWhile (>0) $ tail $ iterate (`div` p) n

main = print $ sum [p * (factExponent n p - factExponent m p - factExponent (n - m) p) | p <- primesToN n]
