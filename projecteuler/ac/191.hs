{-
     A       A
 0'----> 1'----> 2'\  A
 ^                  \
(L)                  ERROR
                    /
 0 ----> 1 ----> 2 /  A
 o   A       A
(O)
-}

gao (v0':v1':v2':v0:v1:v2:[]) = [
	v0' + v1' + v2' + v0 + v1 + v2,
	v0',
	v1',
	v0 + v1 + v2,
	v0,
	v1]

main = do putStrLn $ show . sum . snd $ until ((==30) . fst) (\(f,s) -> (succ f, gao s)) (0, [0,0,0,1,0,0])

