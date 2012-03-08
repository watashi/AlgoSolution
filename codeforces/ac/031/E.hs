import Control.Arrow
import Data.Array
import Data.Char

main = do
	n <- getLine
	l <- getLine
	putStrLn $ snd $ gao (read n) $ reverse $ map (toInteger . digitToInt) l

gao n l = dp!(n,n) where
	dp = listArray ((0,0),(n,n)) [f (i,j) | i <- [0 .. n], j <- [0 .. n]]
	f (0,0) = (0, "")
	f (i,j) = let g x y = (+ l!!(i+j-1) * 10 ^ x) *** (y:) in
		maximum [g a b $ dp!(c,d) | (a,b,c,d) <- [(i,'H',i-1,j), (j,'M',i,j-1)], c >= 0, d >= 0]

{-
WA11: <del>Int</del> Integer
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230215 	Dec 27, 2010 5:18:17 PM 	watashi 	E - TV Game 	Haskell 	Accepted 	30 ms 	1548 KB 
-}
