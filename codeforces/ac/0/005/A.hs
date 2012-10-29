main = do interact (show . gao 0 . lines) where
	gao _ [] = 0
	gao n (h:t) =
		if head h == '+' then
			gao (n + 1) t
		else if head h == '-' then
			gao (n - 1) t
		else
			n * (pred $ length $ dropWhile (/=':') h) + gao n t
{-
#  	When  	Who  	Problem  	Lang  	Verdict  	Time  	Memory
256002 	Jan 21, 2011 10:09:55 AM 	watashi 	5A - Chat Servers Outgoing Traffic 	Haskell 	Accepted 	30 ms 	1500 KB
-}
