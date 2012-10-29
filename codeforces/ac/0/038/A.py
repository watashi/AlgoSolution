r = lambda: map(int, raw_input().split())
r()
d = r()
a, b = r()
print sum(d[a-1:b-1])
## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#235828 	Jan 1, 2011 9:18:19 PM 	watashi 	A - Army 	Python 	Accepted 	60 ms 	2688 KB 
