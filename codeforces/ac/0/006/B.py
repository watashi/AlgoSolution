n, m, c = raw_input().split()
n = int(n)
m = int(m)
a = []
for i in xrange(n):
	a.append(raw_input())
b = {}
for i in xrange(n):
	for j in xrange(m):
		if a[i][j] != '.' and a[i][j] != c:
			for (di, dj) in ((0, 1), (1, 0), (0, -1), (-1, 0)):
				if 0 <= i + di < n and 0 <= j + dj < m and a[i + di][j + dj] == c:
					b[a[i][j]] = True
					break
print len(b)

'''
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
201352 	Nov 30, 2010 7:09:01 PM 	watashi 	B - President's Office 	Python 	Accepted 	60 ms 	2688 KB
'''
