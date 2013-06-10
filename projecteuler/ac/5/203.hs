import Data.List (group, sort)

n = 50

issquarefree x = foldr1 (&&) $ map (\y -> x `mod` y /= 0) $ [i ^ 2 | i <- [2 .. n]]

gao n = if n == 0 then [1] else let gao' = gao $ pred n in zipWith (+) (0 : gao') (gao' ++ [0])

main = do putStrLn $ show $ sum $ map head $ group $ sort $ concat [filter issquarefree $ gao i | i <- [1 .. n]]

