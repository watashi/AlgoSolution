n, m = gets.split.map(&:to_i)
p n.times.map{gets.chars.to_a}.transpose.map{|_| _.uniq.size}.inject(&:*) % 1000000007
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1292102 	Mar 5, 2012 10:57:06 PM 	watashi 	152C - Pocket Book 	Ruby 	Accepted 	130 ms 	5500 KB
