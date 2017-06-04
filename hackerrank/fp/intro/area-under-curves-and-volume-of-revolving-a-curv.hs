import Text.Printf (printf)

-- This function should return a list [area, volume].
solve :: Double -> Double -> [Double] -> [Double] -> [Double]
solve l r a b = [area, volumn]
  where
  f (ai, -1) = ai * (log r - log l)
  f (ai, bi) = ai * (r ** (bi + 1) - l ** (bi + 1)) / (bi + 1)
  terms = a `zip` b
  area = sum $ map f terms
  volumn = pi * sum [f (ai * aj, bi + bj) | (ai, bi) <- terms, (aj, bj) <- terms]

--Input/Output.
main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines
