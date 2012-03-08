main = putStrLn $ show $ uncurry (*) $ snd $ minimum $
	concat [[(t - s!!x * s!!y, (x, y)), (s!!x * s!!z - t, (x, z))] |
		x <- takeWhile (\i -> s!!i <= t + 10000) [1 ..],
		let z = length $ takeWhile (<= t `div` s!!x) s,
		let y = z - 1]
	where
		t = 2000000
		s = [i * (i + 1) `div` 2 | i <- [0 ..]]
