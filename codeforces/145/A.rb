a, b = 2.times.map{gets.chars.to_a}
c = 0
a.zip(b){|i, j| c += 1 if i != j}
p c + (a.count('4') - b.count('4')).abs >> 1
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1152031 	Feb 6, 2012 3:43:31 AM 	watashi 	145A - Lucky Conversion 	Ruby 	Accepted 	250 ms 	13100 KB
