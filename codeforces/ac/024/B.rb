h = Hash.new{|x, y| x[y] = [0] * 52}
c = [25, 18, 15, 12, 10, 8, 6, 4, 2, 1] + [0] * 99
gets.to_i.times do
	gets.to_i.times do |i|
		h[gets][0] += c[i]
		h[$_][i + 1] += 1
	end
end
2.times do
	puts h.max{|x, y| x[1] <=> y[1]}[0]
	h.each{|k, v| v[0], v[1] = v[1], v[0]}
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
301780 	Feb 24, 2011 9:09:52 PM 	watashi 	24B - F1 Champions 	Ruby 	Accepted 	90 ms 	3900 KB
