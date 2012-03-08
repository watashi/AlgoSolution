import List (sort)
m = 15
n = 10 ^ m
digitSum x = if x < 10 then x else let (a,b) = divMod x 10 in digitSum a + b
-- ok x = let y = digitSum x in y /= 1 && (until ((/= 0) . (`mod` y)) (`div` y) x) == 1)
a = dropWhile (<10) $ sort $ [x | s <- [2 .. 9 * m], x <- takeWhile (<n) $ scanl1 (*) $ repeat s, digitSum x == s]
main = do putStrLn $ show $ (length a, a!!29)
