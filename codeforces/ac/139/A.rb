n = gets.to_i
a = gets.split.map(&:to_i)
i = -1
n -= a[(i += 1) % 7] while n > 0
p i % 7 + 1
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1121177 	Jan 27, 2012 9:22:18 PM 	watashi 	139A - Petr and Book 	Ruby 	Accepted 	110 ms 	5500 KB
