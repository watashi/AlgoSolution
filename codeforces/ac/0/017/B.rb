INF = 10 ** 20
n = gets.to_i
gets
d = [INF] * (n + 1)
gets.to_i.times do
	a, b, c = gets.split.map(&:to_i)
	d[b] = [d[b], c].min
end
s = d.inject(&:+) - 2 * INF
p s < INF ? s : -1
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
284141 	Feb 13, 2011 6:59:48 PM 	watashi 	17B - Hierarchy 	Ruby 	Accepted 	200 ms 	3000 KB 
