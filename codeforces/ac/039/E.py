n, m = map(int, raw_input().split())
k = input()
a = [map(int, raw_input().split()) for i in range(k)]
p = input()

if n > m:
	n, m = m, n
	for b in a:
		b[:2] = b[1::-1]

x = [0] * m
y = [1] * m
for b in a:
	b[1] -= 1
	x[b[1]] += 1
	y[b[1]] *= b[2]

z = 0
for i in range(0, m):
	if x[i] == n and y[i] == 1:
		print 0
		exit()
	else:
		z += max(0, n - x[i] - 1)
z -= n - 1

print pow(2, z, p) if n % 2 == m % 2 else 0

# not min(n, m) but max(n, m), the problem becomes 
#When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#235790 	Jan 1, 2011 4:30:59 PM 	watashi 	E - Number Table 	Python 	Accepted 	60 ms 	2760 KB 
