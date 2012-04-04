puts gets.to_i.times.map{
	a = gets.split
	b = a[1..-1].map(&:to_i)
	[b[0] * 100 - b[1] * 50 + b[2..-1].inject(&:+), a[0]]
}.sort[-1][1]

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
395989 	Apr 18, 2011 11:46:18 PM 	watashi 	74A - Room Leader 	Ruby 	Accepted 	110 ms 	3800 KB 
