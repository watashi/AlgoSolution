b, n, c = map(int, raw_input().split())
r = pow(b, n - 1, c) * (b - 1) % c
print r or c
## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#286017 	Feb 16, 2011 5:44:26 PM 	watashi 	17D - Notepad 	Python 	Time limit exceeded on test 29 	2000 ms 	4600 KB



def phi(n):
	i = 2
	m = n
	while i * i <= n:
		if n % i == 0:
			m /= i
			m *= i - 1
			while n % i == 0:
				n /= i
		i += 1
	if n > 1:
		m /= n
		m *= n - 1
	return m

b, n, c = map(int, raw_input().split())
if n > c:
	m = phi(c)
	r = pow(b, (n - 1) % m + m, c)
else:
	r = pow(b, n - 1, c)
r = r * (b - 1) % c
print r or c

