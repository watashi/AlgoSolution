db = dict()
re = input()
for ri in xrange(re):
	name = raw_input()
	num = db.get(name, 0)
	if num:
		print name + str(num)
	else:
		print 'OK'
	db[name] = num + 1

'''
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
200406 	Nov 29, 2010 9:33:19 PM 	watashi 	C - Registration System 	Python 	Accepted 	310 ms 	3624 KB 
'''
