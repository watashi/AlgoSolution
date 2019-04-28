#!/usr/bin/python2

re = input()
for ri in xrange(re):
  r, c = map(int, raw_input().split())
  a = [map(int, raw_input().split()) for i in xrange(r)]
  x = [max(a[i]) for i in xrange(r)]
  y = [max([a[i][j] for i in xrange(r)]) for j in xrange(c)]
  b = [[min(x[i], y[j]) for j in xrange(c)] for i in xrange(r)]
  print "Case #" + str(ri + 1) + ": " + ("YES" if a == b else "NO")
