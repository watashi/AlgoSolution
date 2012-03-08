import Data.List;
main = do getLine >>= putStr . show . sum . map ((^2) . toInteger . length) . group . sort
{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229278 	Dec 23, 2010 10:09:11 PM 	watashi 	B - Choosing Symbol Pairs 	Haskell 	Accepted 	250 ms 	10776 KB
-}
