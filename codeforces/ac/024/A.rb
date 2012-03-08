def gao(e, v, p)
	e[v].map{|w, c| w == p ? 0 : c + gao(e, w, v)}.inject(&:+)
end

n = gets.to_i
e = Array.new(n + 1){[]}
y = 0
(n - 1).times do
	a, b, c = gets.split.map(&:to_i)
	e[a] << [b, 0]
	e[b] << [a, c]
	y += c
end
a, b, c = gets.split.map(&:to_i)
x = gao(e, a, -1)
p [x + c, y - x].min

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
301762 	Feb 24, 2011 8:48:35 PM 	watashi 	24A - Ring road 	Ruby 	Accepted 	90 ms 	4100 KB
