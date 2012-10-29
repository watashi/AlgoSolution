gets.to_i.times do
	n, m, a, b, c, d = gets.split.map(&:to_i)
	x, y = n - (a - c).abs, m - (b - d).abs
	p n * m - x * y * 2 + [x + x - n, 0].max * [y + y - m, 0].max
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
276111 	Feb 6, 2011 2:01:28 PM 	watashi 	15B - Laser 	Ruby 	Idleness limit exceeded on test 19 	80 ms 	3000 KB 
