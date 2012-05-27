import Data.List

main = do getContents >>= putStr . unlines . map reverse . sort . map reverse . tail . lines
