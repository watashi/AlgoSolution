y = 0
for i in range(input()):
	x, m = map(int, raw_input().split())
	l, r = x, x + m
	while l < r and l % 4:
		y ^= l
		l += 1
	while l < r and r % 4:
		r -= 1
		y ^= r
print 'tolik' if y else 'bolik'
#When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#276146 	Feb 6, 2011 2:54:40 PM 	watashi 	15C - Industrial Nim 	Python 	Accepted 	770 ms 	4200 KB 
