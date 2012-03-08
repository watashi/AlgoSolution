n, d = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
s = 0
1.upto(b.size - 1).each do |i|
	next if b[i] > b[i - 1]
	t = (b[i - 1] - b[i]) / d + 1
	s += t
	b[i] += t * d
end
p s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
271700 	Jan 31, 2011 9:38:48 PM 	watashi 	11A - Increasing Sequence 	Ruby 	Accepted 	90 ms 	3000 KB
