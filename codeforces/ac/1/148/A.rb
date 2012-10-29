a = 5.times.map{gets.to_i}
p (1..a.pop).count{|i| a.any?{|j| i % j == 0}}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1144054 	Feb 2, 2012 11:12:24 PM 	watashi 	148A - Insomnia cure 	Ruby 	Accepted 	190 ms 	5500 KB
