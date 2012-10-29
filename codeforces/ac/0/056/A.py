import sys

c = 0
n = input()
for i in range(n):
	s = raw_input()
	try:
		n = int(s)
		if n < 18:
			c += 1
	except:
		if s in 'ABSINTH BEER BRANDY CHAMPAGNE GIN RUM SAKE TEQUILA VODKA WHISKEY WINE'.split():
			c += 1
print c

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#267415 	Jan 29, 2011 8:12:02 PM 	watashi 	56A - Bar 	Python 	Accepted 	60 ms 	2700 KB

