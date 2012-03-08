for i in range(input()):
	n, m, a, b, c, d = map(int, raw_input().split())
	x, y = n - abs(a - c), m - abs(b - d)
	print n * m - x * y * 2 + max(x + x - n, 0) * max(y + y - m, 0)
## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#276113 	Feb 6, 2011 2:06:59 PM 	watashi 	15B - Laser 	Python 	Accepted 	140 ms 	2800 KB
