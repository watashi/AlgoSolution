from math import sqrt
a, n = map(int, raw_input().split())
b = a + n
m = [1] * b
for i in xrange(2, int(sqrt(b)) + 1):
  ii = i * i
  for j in xrange(0, b, ii):
    m[j] = ii
m = map(lambda (x, y): x / y, zip(range(b), m))
print sum(m[a:b])
