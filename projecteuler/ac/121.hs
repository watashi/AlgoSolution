import Data.Ratio ((%), numerator, denominator)

gao n = gao' 0 0 0
	where gao' k b r
		| k == n	= if b > r then 1 else 0
		| otherwise	= let k' = succ k in 1 %  succ k' * gao' k' (succ b) r + k' % succ k' * gao' k' b (succ r)

main = do putStrLn $ show $ (\x -> denominator x `div` numerator x) $ gao 15
