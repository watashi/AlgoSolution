import Data.List

isPalindromic x = let y = show x in y == reverse y

squares = [i ^ 2 | i <- [0 .. floor $ sqrt $ fromIntegral $ limit]]

ssquares = scanl1 (+) squares

limit = 100000000

answer = map head $ group $ sort $ [a - b | a <- ssquares, b <- takeWhile (<a) $ dropWhile (<=a-limit) ssquares, isPalindromic (a - b)] \\ [a | a <- squares, isPalindromic a]

main = putStrLn $ show $ sum $ answer

