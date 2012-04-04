n = gets.to_i
1.upto(n - 1){|i| puts 1.upto(n - 1).map{|j| (i * j).to_s(n)} * ' '}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
396522 	Apr 19, 2011 6:57:24 PM 	watashi 	39H - Multiplication Table 	Ruby 	Accepted 	90 ms 	3800 KB
