n = gets.to_i
h = {}
n.times do
	h[gets.chomp] = [0, 0, 0]
end
(n * (n - 1) / 2).times do
	a, b, c, d = gets.split(/[ :-]/)
	c = c.to_i
	d = d.to_i
	if c < d
		a, b, c, d = b, a, d, c
	end
	if c == d
		h[a][0] += 1
		h[b][0] += 1
	else
		h[a][0] += 3
	end
	h[a][1] += c - d
	h[a][2] += c
	h[b][1] += d - c
	h[b][2] += d
end
puts h.sort{|a, b| b[1] <=> a[1]}.map{|_| _[0]}[0, n / 2].sort

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
300718 	Feb 23, 2011 3:59:55 PM 	watashi 	19A - World Football Cup 	Ruby 	Accepted 	110 ms 	4100 KB 
