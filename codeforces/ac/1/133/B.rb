p (gets.chop.each_char.map{|_| (8 + '><+-.,[]'.index(_)).to_s(2)} * '').to_i(2) % 1000003
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1127807 	Jan 31, 2012 9:28:11 AM 	watashi 	133B - Unary 	Ruby 	Accepted 	110 ms 	5500 KB
