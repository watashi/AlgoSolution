triangle = [n * (n + 1) `div` 2 | n <- [1 ..]]
pentagonal = [n * (3 * n - 1) `div` 2 | n <- [1 ..]]
hexagonal = [n * (2 * n - 1) | n <- [1 ..]]
gao t@(t0:ts) p@(p0:ps) h@(h0:hs)
	| t0 == p0 && t0 == h0 = t0 : gao ts ps hs
	| t0 <= p0 && t0 <= h0 = gao ts p h
	| p0 <= t0 && p0 <= h0 = gao t ps h
	| h0 <= t0 && h0 <= t0 = gao t p hs
main = putStrLn $ show $ take 3 $ gao triangle pentagonal hexagonal
	
