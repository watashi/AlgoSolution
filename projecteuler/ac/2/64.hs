import Data.List

main =
	putStrLn $ show $ length $ filter (even . length . cFracSqrt) $ 
		[1 .. 10000] \\ [x * x | x <- [1 .. 100]]

isqrt n =
	last $ takeWhile((<= n) . (^ 2)) [1 ..]

cFracSqrt d = cFracSqrt' d 0 1
	where cFracSqrt' d c q
		| a == 2 * t = [a]
		| otherwise = a : cFracSqrt' d c' q'
		where
			t = isqrt d
			a = (t + c) `div` q
			c' = a * q - c
			q' = (d - c' ^ 2) `div` q

