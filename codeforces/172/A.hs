main = do getContents >>= print . length . takeWhile (/='*') . foldl1 (zipWith (\i j -> if i == j then i else '*')) . tail . lines
