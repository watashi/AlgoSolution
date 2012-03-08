n, m = gets.split.map(&:to_i)
a = []
m.times do
	a << gets.split.map(&:to_i)
end
s = 0
1.upto(n) do |i|
	b = 0
	d = -1
	a.each do |l, r, t, c|
		next if i < l || i > r
		if d == -1 || t < d
			d = t
			b = c
		end
	end
	s += b
end
p s
