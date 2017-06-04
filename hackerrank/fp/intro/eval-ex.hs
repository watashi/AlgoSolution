solve :: Double -> Double
solve x = sum $ take 10 $ scanl (\i j -> i * x / j) 1 [1..]

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words
