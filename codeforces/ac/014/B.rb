class Range
	def ^(other)
		([first, other.first].max .. [last, other.last].min)
	end
end

n, x0 = gets.split.map{|i| i.to_i}
r = []
n.times do
	a, b = gets.split.map{|i| i.to_i}
	a, b = b, a if a > b
	r <<= (a .. b)
end
r = r.inject{|i, j| i ^ j}

unless r.first <= r.last then
	p -1
else
	p r.include?(x0) ? 0 : [(r.first - x0).abs, (r.last - x0).abs].min
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
211959 	Dec 7, 2010 10:47:20 PM 	watashi 	B - Young Photographer 	Ruby 	Accepted 	90 ms 	2996 KB
