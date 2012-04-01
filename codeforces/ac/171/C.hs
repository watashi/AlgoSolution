main = do getLine >>= print . sum . zipWith (*) [1..] . map read . tail . words
