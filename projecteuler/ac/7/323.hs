import Text.Printf

probability :: [Double]
probability = 0: iterate (/2) 0.5

probabilityND :: Int -> [Double]
probabilityND n = zipWith (-) acc $ 0: acc
  where
    acc = map (^n) $ scanl1 (+) probability


{-
\forall n>0
p1(n) = \frac{1}{2^n}
f1(n) = 1-\frac{1}{2^n}
f32(n) = (1-\frac{1}{2^n)})^32
p32(n) = f32(n)-f32(n-1)
-}

ans :: String
ans = printf "%.10f" $ sum $ take 100 $zipWith (*) [0..] $ probabilityND 32
