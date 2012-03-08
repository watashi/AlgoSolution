n, m, k = gets.split.map(&:to_i)
a = [nil] * n
n.times do
	r, c = gets.split.map(&:to_i)
	r -= 1
	a[r] = a[r] ? [a[r], c].min : c 
end
p [a.compact.inject(:+), k].min
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
242404 	Jan 8, 2011 9:38:36 PM 	watashi 	A - What is for dinner? 	Ruby 	Accepted 	80 ms 	3000 KB
