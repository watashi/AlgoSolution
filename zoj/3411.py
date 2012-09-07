def gcd(a, b):
    return (b and (gcd(b, a % b),) or (a,))[0]

while True:
    try:
        n, m, a, b = map(int, raw_input().split())
        b = b - a + 1
        xs = map(int, raw_input().split())

        p = [0 for i in range(m + 1)]
        p[0] = 1
        for x in xs:
            x -= a
            q = [0 for i in range(m + 1)]
            for y in range(b):
                z = abs(y - x)
                for j in range(z, m + 1):
                    q[j] += p[j - z]
            p = q

        num = sum(p)
        den = b ** n
        g = gcd(num, den)
        print str(num / g) + '/' + str(den / g)
    except EOFError:
        break

'''
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
340     2010-10-07 12:36:34     Accepted    F   Python  1130    320     watashi@Zodiac  Source
'''

# 2012-09-07 15:53:07 | Accepted | 3411 | Python | 1100 | 320 | watashi | Source
