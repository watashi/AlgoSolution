r = lambda: map(int, raw_input().split())
n, m = r()
a = r()
a.sort()

j = 0
k = 0
v = a[0]
for i in xrange(1, n):
  m -= (a[i] - a[i - 1]) * (i - j)
  while m < 0:
    m += a[i] - a[j]
    j += 1
  if k < i - j:
    k = i - j
    v = a[i]
print '%d %d' % (k + 1, v)
