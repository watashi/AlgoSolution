n, m, k = gets.split.map(&:to_i)
p m > n + k ? 0 : m > k ? 1 - 0.upto(k).map{|i| (m - i) / (n + i + 1.0)}.inject(&:*) : 1
__END__
# tooold
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#309249 	Feb 28, 2011 12:08:30 PM 	watashi 	26D - Tickets 	Ruby 	Accepted 	80 ms 	3800 KB 
