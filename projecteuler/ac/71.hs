import Data.Ratio

flor v x = flor' (0, 1) (1, 0)
	where flor' l@(a,b) r@(c,d) = if f > x then l else if w < v then flor' m r else flor' l m
		where
			e = a + c
			f = b + d
			m = (e, f)
			w = e % f

main = putStrLn $ show $ fst ans % snd ans
	where ans = flor (3 % 7) 1000000

