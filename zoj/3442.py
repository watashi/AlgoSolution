from __future__ import division
import sys
from cmath import *

arg = phase
real = lambda c: c.real
imag = lambda c: c.imag
conj = lambda c: c.conjugate()
gao = lambda f: 0 if abs(f) < 5e-7 else f
i = 1j
for line in sys.stdin:
    ans = eval(line)
    print "%+.6f%+.6f*i" % (gao(ans.real), gao(ans.imag))

# 2012-09-07 15:56:16 | Accepted | 3442 | Python | 60 | 1692 | watashi | Source
