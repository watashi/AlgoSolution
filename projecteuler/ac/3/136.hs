{-
n = (x+y)^2 - x^2 - (x-y)^2
  = 4xy - x^2
  = x(4y-x)
y < x < 4y

n = uv, 4 | u + v

== n = ab, odd a, odd b
=> a + b = 4y
=> a = 4i + 1, b = 4j + 3
=> n = 4k + 3
x_1=n, y_1=(n+1)/4
x_?=max(a,b), y_?=(a+b)/4
=> n = p

== n = 2ab, odd a, odd b
empty

== n = 4ab, 1 < a <= b, odd a, odd b
x_1=2ab, y_1=(ab+1)/2
x_2=2b, y_2=(a+b)/2

== n = 4
=> ok
== n = 4p, odd p
x_1=2p, y_2=(p+1)/2>=2
=> ok

== n = 8ab, odd a, odd b
empty

== n = 16ab, 1 < a <= b
x_1=4ab, y_1=ab+1
x_2=4b, y_2=a+b

== n = 16
=> ok
== n = 16p, odd p
x_1=4p, y_1=p+1>=4
=> ok

-}

import ProjectEuler.NumberTheory.Primes (primesTo)

main :: IO ()
main = do
  let limit = 5 * 10 ^ (7::Int)
      primeList = primesTo limit
      a = filter (\i -> i `rem` 4 == 3) primeList
      b = takeWhile (<limit) $ map (4*) $ (1:) $ tail primeList
      c = takeWhile (<limit) $ map (16*) $ (1:) $ tail primeList
  print $ length $ a ++ b ++ c
