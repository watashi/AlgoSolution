n, m = gets.split.map(&:to_i)
a = Array.new(n){gets.chars.to_a}
b = (['0'] * m).zip(*a).map(&:max)
p a.count{|_| _.zip(b).any?{|i, j| i == j}}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1292035 	Mar 5, 2012 10:35:43 PM 	watashi 	152A - Marks 	Ruby 	Accepted 	130 ms 	5500 KB
