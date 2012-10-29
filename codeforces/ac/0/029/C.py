n = input()
e = {}
for i in xrange(n):
	a, b = map(int, raw_input().split())
	e.setdefault(a, []).append(b)
	e.setdefault(b, []).append(a)

for k, v in e.items():
	if len(v) == 1:
		print k,
		p, k = k, v[0]
		break

while True:
	print k,
	v = e[k]
	if len(v) == 1:
		break
	p, k = k, v[0] if p != v[0] else v[1]

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#229779 	Dec 25, 2010 10:08:42 AM 	watashi 	C - Mail Stamps 	Python 	Accepted 	910 ms 	18888 KB 
