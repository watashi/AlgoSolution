A = a = gets.to_i

x = 0
while a % 12 == 0
	a /= 12
	x += 1
end

b = [2, 13]
999.times{b.push 13 * b[-1] - 12 * b[-2]}	# 300.times => RE
y = 0
y += 1 while b[y] < a

if b[y] != a
	puts :NO
else
	z = 2 * x + y
	c = []
	(z / 2).downto(0){|i| c << b[z - 2 * i] * 12 ** i if i != x}
	puts :YES
	p 1, z + 1, c.size, *c
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235802 	Jan 1, 2011 5:48:26 PM 	watashi 	D - Interesting Sequence 	Ruby 	Accepted 	90 ms 	3804 KB

# a b (13b-12a) 12a => no matter which method, both get 12*12b !!
# so we can always put all 13b[-1]-12b[-2] at the begining of sequence !!
