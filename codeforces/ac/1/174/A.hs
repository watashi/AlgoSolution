main = do interact (unlines . gao . map read . words)
gao (n:m:a) = if d <= m then map (\i -> show $ i + (m - d) / n) c else ["-1"] where
    b = maximum a
    c = map (b-) a
    d = sum c
