a1, b1, c1 = map(int, raw_input().split())
a2, b2, c2 = map(int, raw_input().split())
x = c1 * b2 - c2 * b1
y = a1 * c2 - a2 * c1
z = a1 * b2 - a2 * b1
print 0 if (not (a1 or b1) and c1) or (not (a2 or b2) and c2) else 1 if z else 0 if x or y else -1
## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#283359 	Feb 12, 2011 6:15:21 PM 	watashi 	21B - Intersection 	Python 	Accepted 	80 ms 	2700 KB
