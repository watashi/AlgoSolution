import List
main = do interact (show . gao . map (map (=='B')) . lines)
gao a = if b == 16 then 8 else b where
	b = f a + f (transpose a)
	f = length . filter id . map and
--258603 	Jan 21, 2011 9:04:09 PM 	watashi 	7A - Kalevitch and Chess 	Haskell 	Accepted 	30 ms 	1500 KB 
