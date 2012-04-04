gets
a, b = gets.split.map(&:to_i), [2000]
while a.any? && p = a.index(b.size) do
	b << b[-1] + p + 1
	a = a[p + 1 .. -1]
end
b[0] = b.size - 1
puts b * ' '
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
396503 	Apr 19, 2011 6:50:08 PM 	watashi 	39B - Company Income Growth 	Ruby 	Accepted 	90 ms 	3800 KB 
