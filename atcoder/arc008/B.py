def read():
  h = {}
  for c in raw_input():
    h[c] = h.get(c, 0) + 1
  return h

raw_input()
a = read()
b = read()
try:
  print max(map(lambda c: (a[c] + b[c] - 1) / b[c], a.keys()))
except KeyError:
  print -1
