n = gets.to_i
a = [[-1e9, -1e9]] + 1.upto(n).map{|i| gets.split.map(&:to_i) << i}.sort + [[1e9, 1e9]]
b = a.map{1}
1.upto(n + 1){|i| b[i] = b[i - 1] && a[i - 1][1] <= a[i][0]}
c = a.map{1}
(n).downto(0){|i| c[i] = c[i + 1] && a[i][1] <= a[i + 1][0]}
d = (1 .. n).select{|i| b[i - 1] && c[i + 1] && a[i - 1][1] <= a[i + 1][0]}.map{|i| a[i][2]}
p d.size
puts d.sort * ' '
__END__
O(n) ? IDEA?
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230190 	Dec 27, 2010 12:57:59 PM 	watashi 	C - Schedule 	Ruby 	Accepted 	170 ms 	3336 KB
