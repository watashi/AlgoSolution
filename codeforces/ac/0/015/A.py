n, t = map(int, raw_input().split())
b = []
for i in range(n):
	x, a = map(int, raw_input().split())
	b.extend([x * 2 - a, x * 2 + a])
b.sort()
c = 2
for i in range(2, n + n, 2):
	c += cmp(b[i] - b[i - 1], t + t) + 1
print c
## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#276097 	Feb 6, 2011 1:40:37 PM 	watashi 	15A - Cottage Village 	Python 	Accepted 	60 ms 	2700 KB 
