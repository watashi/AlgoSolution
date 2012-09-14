import re
import sys

array = []
pat = re.compile(r'\[\s*(\d+)\s*:\s*(\d+)\s*\]\s*=\s*(.*)')
sep = re.compile(r'[^-\d]+')
for line in sys.stdin:
    tok = pat.search(line)
    begin = int(tok.group(1))
    end = int(tok.group(2))
    todo = sep.split(tok.group(3))
    if todo[-1] == '':
        todo.pop()
    print ', '.join(map(str, array[begin:end]))
    array[begin:end] = map(int, todo)

'''
Run ID  Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
399     2010-11-11 23:10:09     Accepted    A   Python  20  452     watashi@Zodiac  Source
'''

# 2012-09-07 15:54:01 | Accepted | 3427 | Python | 20 | 456 | watashi | Source
