gets
a = gets.split.map(&:to_i)
p a.count{|i| a.inject(i, &:+).even?}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
871349 	Nov 15, 2011 3:08:06 PM 	watashi 	129A - Cookies 	Ruby 	Accepted 	110 ms 	3500 KB 
