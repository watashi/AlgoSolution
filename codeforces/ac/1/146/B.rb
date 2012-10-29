a, b = gets.split
a = a.to_i + 1
a += 1 until a.to_s.gsub(/[^47]/, '') == b
p a
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1120233 	Jan 27, 2012 1:24:23 PM 	watashi 	146B - Lucky Mask 	Ruby 	Accepted 	580 ms 	5600 KB
