from math import sqrt

re = input()
for ri in range(re):
    n, m = map(int, raw_input().split())
    if n <= m:
        ans = -1
    elif n == m + 1:
        # x = 0; y = m; z = 0;
        ans = 0
    else:
        # 2x(y+1)-(x+y) = d
        sn = int(sqrt(n / 2)) + 1
        ans = 0x3f3f3f3f
        d = n - m
        for x in range(1, sn):
            if (d - x) % (x + x - 1):
                continue
            y = (d - x) / (x + x - 1)
            z = m - x - y
            if 0 <= z and z < ans:
                ans = z
#       for y in range(0, sn):
#           if (d + y) % (y + y + 1):
#               continue
#           x = (d + y) / (y + y + 1)
#           z = m - x - y
#           if 0 <= z and z < ans:
#               ans = z
        if ans == 0x3f3f3f3f:
            ans = -1
    print ans

# 2012-09-07 15:52:36 | Accepted | 3407 | Python | 1390 | 320 | watashi | Source
