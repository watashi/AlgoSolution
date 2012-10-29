n, p1, p2, p3, t1, t2 = gets.split.map(&:to_i)
s, t = 0, 0
n.times do |i|
	l, r = gets.split.map(&:to_i)
	if i > 0
		[[p1, t1], [p2, t2], [p3, 1e9]].each do |pi, ti|
			d = [ti, l - t].min
			s += d * pi
			t += d
		end
	end
	s += (r - l) * p1
	t = r
end
p s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
275098 	Feb 4, 2011 7:04:56 PM 	watashi 	10A - Power Consumption Calculation 	Ruby 	Accepted 	80 ms 	3000 KB 
