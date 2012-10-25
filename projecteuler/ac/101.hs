import Data.Ratio

zero = fromIntegral 0
one = fromIntegral 1

(@:) p x = foldr1 (\i j -> j * x + i) p

infixl 7 @*
(@*) p [] = []
(@*) p (h:t) = map (*h) p @+ (zero: p @* t)

infixl 6 @+
(@+) p [] = p
(@+) [] q = q
(@+) (a:b) (c:d) = a+c: b @+ d

polynomials s = reverse $ p (length s - 1) s
  where
    p 0 s = [map (\i -> [i]) s]
    p n s = [(p1 @* f [n + x, -1] @+ p2 @* f [-x, 1]) @* [1 % toInteger n] |
      (x, p1, p2) <- zip3 [1 ..] h $ tail h]: t
      where
        t@(h:_) = p (pred n) s
        f = map fromIntegral

main = print $ sum $ [ys'!!k | (op,k) <- zip ops [1 .. degree], ys' <- [map (op @:) xs], ys'!!k /= ys!!k]
  where
    degree = 10
    function = [(-one) ^ i | i <- [0 .. degree]]
    xs = map fromIntegral [1 .. degree + 1]
    ys = map (function @:) xs
    ops = map head $ polynomials ys

