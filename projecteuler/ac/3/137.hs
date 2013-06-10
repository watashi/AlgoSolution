{-
let A_F(x)=a

a*x^2+(a+1)*x-a=0

       sqrt(5a^2+2a+1) - (a+1)
ans = -------------------------
                 2a

b^2 = 5a^2+2a+1
5b^2 = (5a+1)^2 + 4

== odd a
((5a+1)/2)^2 - 5(b/2)^2 = -1

== even a
(2v+1)^2 = 5(2u)^2+2(2u)+1
4v^2+4v+1 = 20u^2+4u+1
v(v+1) = u(5u+1)
???

[Transformations](http://en.wikipedia.org/wiki/Pell%27s_equation#Transformations)
If u2 − dv2 = −4, and {x,y} = {(u2 + 3)u/2, (u2 + 1)v/2}, then x2 − dy2 = −1.
-}

import ProjectEuler.NumberTheory.Power
import ProjectEuler.NumberTheory.ContinuedFraction

import Control.Monad
import Data.Ratio

solutions :: [(Integer, Integer)]
solutions = [(a, v) |
  (x, y) <- solveNegPell 5,
  let u = icbrt $ 2 * x,
  (u * u + 3) * u == 2 * x,
  let v = 2 * y `quot` (u * u + 1),
  (u * u + 1) * v == 2 * y,
  let (a, m) = (u - 1) `quotRem` 5,
  a > 0,
  m == 0]

main :: IO ()
main = do
  forM_ (zip [1 .. 20::Int] solutions) $ \(i, (a, b)) ->
    putStrLn $ show i ++ ": " ++ show (a, (b - a - 1) % (2 * a))
