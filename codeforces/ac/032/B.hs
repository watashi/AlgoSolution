main = do getLine >>= putStr . gao
gao [] = []
gao ('.':x) = '0':gao x
gao ('-':'.':x) = '1':gao x
gao ('-':'-':x) = '2':gao x

{-
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230221 	Dec 27, 2010 5:51:21 PM 	watashi 	B - Borze 	Haskell 	Accepted 	30 ms 	1540 KB 
-}
