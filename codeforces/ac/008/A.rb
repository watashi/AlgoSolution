s, a, b = readlines.map(&:chop)
r = /#{a}.*#{b}/
puts %w(fantasy forward backward both)[(s =~ r ? 1 : 0) | (s.reverse =~ r ? 2 : 0)]
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
268129 	Jan 31, 2011 11:19:08 AM 	watashi 	8A - Train and Peter 	Ruby 	Accepted 	140 ms 	8000 KB
268127 	Jan 31, 2011 11:15:15 AM 	watashi 	8A - Train and Peter 	Ruby 	Accepted 	220 ms 	8000 KB 
