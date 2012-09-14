import sys

def gao(x, y):
    n = len(x)
    add, sub = 0, 0
    for i in range(2 ** n):
        z = 0
        c = 0
        for j in range(n):
            if i & (1 << j):
                z += x[j]
                c += 1
        if y > z:
            if c % 2:
                sub += pow(y - z, n)
            else:
                add += pow(y - z, n)
    return add - sub

for line in sys.stdin:
    x, y, a, b, k = map(float, line.split())
    y += x
    if a > b:
        a, b = b, a
    if a == 0 and b == 0:
        ans = (y <= k + 1e-8 and [1] or [0])[0]
    elif a == 0:
        ans = gao([b], y + k) - gao([b], y - k)
        ans /= b
    else:
        ans = gao([a, b], y + k) - gao([a, b], y - k)
        ans /= 2 * a * b
    print '%.6f' % max(0, min(1, ans))

'''
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
1547    2010-10-07 14:00:31     Accepted    H   Python  560     320     東風谷早苗
'''

# 2012-09-07 15:53:26 | Accepted | 3413 | Python | 610 | 320 | watashi | Source
