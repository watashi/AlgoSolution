class DisjointSet
	def initialize(n)
		@p = [*0..n]
	end
	
	def root(i)
		i == @p[i] ? i : @p[i] = root(@p[i])
	end

	def setp(i, j)
		i = root(i)
		j = root(j)
		return if i == j
		@p[i] = j
	end
end

n = gets.to_i
e = n.times.map{[]}
d = DisjointSet.new(n)
x = []
(2..n).each{
	a, b = gets.split.map(&:to_i)
	x << [a, b] unless d.setp(a, b)
}
p x.size
(2..n).each{|i|
	next unless d.setp(i - 1, i)
	puts "#{x[0][0]} #{x[0][1]} #{i - 1} #{i}"
	x.shift
}

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219480 	Dec 15, 2010 6:04:59 PM 	watashi 	D - Roads not only in Berland 	Ruby 	Accepted 	90 ms 	3004 KB
