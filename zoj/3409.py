#!/usr/bin/python

from math import sqrt

class vector:
    EPS = 1e-8

    def __init__(self, *p):
        if type(p[0]) is list:
            self.p = map(float, p[0])
        else:
            self.p = map(float, p)

    def length(self):
        return sqrt(self * self)

    def __add__(lhs, rhs):
        return vector(map(float.__add__, lhs.p, rhs.p))

    def __sub__(lhs, rhs):
        return vector(map(float.__sub__, lhs.p, rhs.p))

    def __mul__(lhs, rhs):
        return sum(map(float.__mul__, lhs.p, rhs.p))

    def scale(lhs, rhs):
        return vector(lhs.p[0] * rhs, lhs.p[1] * rhs, lhs.p[2] * rhs)

    def vpvn(lhs, rhs):
        if lhs.length() < vector.EPS:
            vp = vector(0, 0, 0)
            vn = vector(0, 0, 0)
        else:
            vp = rhs.scale((lhs * rhs) / (rhs * rhs))
            vn = lhs - vp
    #   print vn * rhs
        return (vp, vn)

def main():
    while True:
        try:
            line = raw_input().split()
        except EOFError:
            break
        n = int(line[0])
        m = float(line[1])
        m0 = float(line[3])
        v0 = float(line[4])
        p = [vector(0, 0, 0)]
        for i in xrange(1, n + 1):
            p.append(vector(raw_input().split()))

        v = vector(0, 0, 0)
        t = 0
        flag = True
        for i in xrange(n):
            mm = m
            m -= m0
            w = p[i + 1] - p[i]
            vp, vn = v.vpvn(w)

            v0n = mm * vn.length() / m0
            if v0n > v0 + vector.EPS:
                flag = False
                break

            v0p = sqrt(abs(v0 * v0 - v0n * v0n))
            v = (vp.scale(mm) + w.scale(m0 * v0p / w.length())).scale(1 / m)
            if v * w < vector.EPS:
                flag = False
                break

            t += w.length() / v.length()

        if flag:
            print '%.2f' % t
        else:
            print 'Another kind of KKV.'

if __name__ == '__main__':
    main()

# 2012-09-07 16:57:24 | Accepted | 3409 | Python | 5030 | 320 | watashi | Source
