import sys

for line in sys.stdin:
    a, b, n = map(int, line.split())
    m = 2 * (a + b)
    c = 2 if n % 4 == 0 else m
    c *= pow((a - b) * (b - a), n / 4, m)
    print (c - 1) % m

#Run ID     Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
#687    2011-01-30 14:15:49     Accepted    B   Python  10  320     watashi@ArcOfDream  Source

# 2012-09-07 15:58:07 | Accepted | 3458 | Python | 10 | 320 | watashi | Source
