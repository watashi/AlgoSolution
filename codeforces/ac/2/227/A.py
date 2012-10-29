a, b, c = [eval(raw_input().replace(' ', '+') + 'j') for i in xrange(3)]
print ['TOWARDS', 'RIGHT', 'LEFT'][cmp(((b - a) * (c - b).conjugate()).imag, 0)]
