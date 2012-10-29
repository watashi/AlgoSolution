import List
main = do getLine; getLine >>= print . (pi*) . foldl1 subtract . sort . map ((**2) . read) . words
