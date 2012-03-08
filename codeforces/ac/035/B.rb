I = open('input.txt')
O = open('output.txt','w')
n, m, k = I.gets.split.map &:to_i
t = [nil] * (n *= m)
k.times do
	a, b, c, d = I.gets.split
	if /-1/ then
		c = t.index b
		if c then
			t[c] = nil
			O.puts "#{c / m + 1} #{c % m + 1}"
		else
			O.puts '-1 -1'
		end
	else
		b = (b.to_i - 1) * m + (c.to_i - 1)
		b += 1 while b < n && t[b]
		t[b] = d if b < n
	end
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230247 	Dec 27, 2010 7:34:30 PM 	watashi 	B - Warehouse 	Ruby 	Accepted 	170 ms 	3136 KB 
