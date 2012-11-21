import Control.Arrow

main = do
  [n, m] <- fmap (map read . words) getLine
  s <- getLine
  let (x, y) = gao m s
  print x
  putStrLn y

gao 2 s = min (go s $ cycle "AB") (go s $ cycle "BA")
  where
    go a b = (length $ filter id $ zipWith (/=) a b, take (length a) b)

gao _ s = go s
  where
    go (x:y:z)
      | x == y    = first succ $ second ([x,y']++) $ go z
      | otherwise = second (x:) $ go (y:z)
      where
        z' = if null z then x else head z
        y' = head $ filter (`notElem`[x,z']) "ABC"
    go s = (0, s)
