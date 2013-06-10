gao l@(a,b) r@(c,d) =
	let e = a + c; f = b + d; m = (e, f) in
	if f <= 12000 then 1 + gao l m + gao m r else 0

main = putStrLn $ show $ gao (1, 3) (1, 2)
		
