s = map(lambda c: c == 'o' and '1' or '0', raw_input())
n = len(s)

x = set()
for i in xrange(n):
  x.add(int("".join(s), 2))
  s = s[1:] + [s[0]]

dp = [n for i in xrange(1 << n)]
dp[0] = 0
for i in xrange(1 << n):
  for j in x:
    dp[i | j] = min(dp[i | j], dp[i] + 1)

print dp[-1]
