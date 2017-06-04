gao :: Ord a => [a] -> [Int]
gao a = map d $ tail $ scanl f [] $ [0 ..] `zip` a
  where
  f t h@(_, e) = h: dropWhile ((>=e) . snd) t
  d ((i, _): (j, _): _) = i - j
  d [(i, _)] = i + 1
  d [] = undefined
  
main :: IO ()
main = do
  _ <- getLine
  a <- fmap (map read . words) getLine
  let l = gao a
      r = reverse $ gao $ reverse a
      s = zipWith3 (\i j k -> (i + j - 1) * k) l r a
  print $ maximum s