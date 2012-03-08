n, h = map(int, raw_input().split())
dp = [[0 for j in xrange(n + 1)] for i in xrange(n + 1)]
dp[0] = [1 for j in xrange(n + 1)]
for i in xrange(n + 1):
	for j in xrange(1, n + 1):
		for k in xrange(i):
			dp[i][j] += dp[k][j - 1] * dp[i - 1 - k][j - 1]
print dp[n][n] - (h > 0 and [dp[n][h - 1]] or [0])[0]

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#209234 	Dec 6, 2010 7:17:30 PM 	watashi 	D - How many trees? 	Python 	Accepted 	60 ms 	2688 KB 

