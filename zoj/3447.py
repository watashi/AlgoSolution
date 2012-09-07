from operator import mul

def gao(a):
    return reduce(mul, a) + 1

def foo(a):
    while (len(a) > 1):
        a.sort()
        a[0:2] = [gao(a[0:2])]
    return a[0]

def bar(a, k):
    while (len(a) > 1):
        a.sort(None, None, True)
        a[0:k] = [gao(a[0:k])]
    return a[0]

while True:
    try:
        n, k = map(int, raw_input().split())
    except EOFError:
        break
    a = map(int, raw_input().split())
    print foo(list(a)) - bar(list(a), k)

#Run ID     Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
#649    2010-12-26 15:54:02     Accepted    B   Python  40  320     watashi@ArcOfDream  Source

# 2012-09-07 15:56:59 | Accepted | 3447 | Python | 40 | 320 | watashi | Source
