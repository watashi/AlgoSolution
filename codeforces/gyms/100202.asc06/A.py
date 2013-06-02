import os, sys

if os.getenv('USER') != 'watashi':
  sys.stdin = open('brackets.in', 'r')
  sys.stdout = open('brackets.out', 'w')

n = 52
dp = [[1 if i == 0 else 0 for j in xrange(n)] for i in xrange(n)]
for i in xrange(1, n):
  for j in xrange(1, n):
    for k in xrange(1, i + 1):
      dp[i][j] += dp[i - k][j] * dp[k - 1][j - 1]

ri = 0
while True:
  i, j = map(int, raw_input().split())
  if i == 0 or j == 0:
    break
  if ri > 0:
    print
  ri += 1
  print "Case %d: %d" % (ri, dp[i][j] - dp[i][j - 1])
