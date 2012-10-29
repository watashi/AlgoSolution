def gao(e, p, q)
	l, t = 0, [0, 0]
	e[p].each do |i|
		next if i == q
		ll, dd = gao(e, i, p)
		l = [l, ll].max
		t <<= dd + 1
	end
	t.sort!{|a, b| b <=> a}
	return [[l, t[0] + t[1]].max, t[0]]
end

n = gets.to_i
e = Array.new(n).map{[]}
ee = []
(n - 1).times do
	a, b = gets.split.map{|i| i.to_i - 1}
	e[a] <<= b
	e[b] <<= a
	ee <<= [a, b]
end
p ee.map{|p| gao(e, p[0], p[1])[0] * gao(e, p[1], p[0])[0]}.max

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
212753 	Dec 9, 2010 2:17:30 PM 	watashi 	D - Two Paths 	Ruby 	Accepted 	310 ms 	3096 KB
