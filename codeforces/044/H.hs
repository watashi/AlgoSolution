import Data.Char

main = do getLine >>= print . (\x -> sum (gao x) - if ok x then 1 else 0)  . map digitToInt

ok [a] = True
ok (a:b:c) = abs (a - b) <= 1 && ok (b:c)

gao [a] = take 10 $ repeat 1
gao (a:b:c) = [d!!j + if odd (i + b) then d!!(j+1) else 0 | i <- [0 .. 9], j <- [div (i + b) 2]] where
	d = gao (b:c)

--# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
--404520 	Apr 21, 2011 3:02:55 PM 	watashi 	44H - Phone Number 	Haskell 	Accepted 	30 ms 	2000 KB 
