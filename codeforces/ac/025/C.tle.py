# import psyco
# psyco.full()
n = input()
w = [map(int, raw_input().split()) for i in xrange(n)]
s = sum(map(sum, w)) / 2
for k in xrange(input()):
	a, b, c = map(int, raw_input().split())
	a -= 1
	b -= 1
	if c < w[a][b]:
		s = 0
		for i in xrange(n):
			for j in xrange(i + 1, n):
				ww = min(w[i][j], min(w[i][a] + c + w[b][j], w[i][b] + c + w[a][j]))
				w[i][j] = ww
				w[j][i] = ww
				s += ww
	print s,

# tle11
