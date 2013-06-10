import IO

main = do
	handle <- openFile "102triangles.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ length $ filter gao $ lines input
	where gao str = ab == bc && bc == ca
		where
			(ax, ay, bx, by, cx, cy) = read ("(" ++ str ++ ")")
			ab = signum $ ax * by - ay * bx
			bc = signum $ bx * cy - by * cx
			ca = signum $ cx * ay - cy * ax
