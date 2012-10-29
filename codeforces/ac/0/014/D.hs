import Data.Array (accumArray, (!))
import Data.List (sort)

gao n e = maximum [fst (gao' a b) * fst (gao' b a) | (a, b) <- e] where
        e' = accumArray (flip (:)) [] (1, n) $ concat [e, [(b, a) | (a, b) <- e]]
        gao' p q = (\(a, b) -> let b' = reverse $ sort b in (max a $ (b'!!0)+(b'!!1), b'!!0)) $
                foldl (\(a,b) (c,d) -> (max a c, d+1:b)) (0, [0, 0]) [gao' i p | i <- e'!p, i /= q]

main = do
        v <- getLine
        e <- getContents
        putStrLn $ show $ let n = read v in gao n $ map ((\[a,b]->(a,b)) . map read . words) $ lines e
{-
WA25!! max a (b'!!0)+(b'!!1) => max a $ (b'!!0)+(b'!!1)
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
234865 	Dec 29, 2010 1:58:01 PM 	watashi 	D - Two Paths 	Haskell 	Accepted 	50 ms 	1548 KB
-}
