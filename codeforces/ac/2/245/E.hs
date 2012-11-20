main = getLine >>= print . snd . foldl f (0, 0)

f (a, b) '+' = (a + 1, max (a + 1) b)
f (0, b) '-' = (0, b + 1)
f (a, b) '-' = (a - 1, b)
