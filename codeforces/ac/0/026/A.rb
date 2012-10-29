require 'prime'
p 1.upto(gets.to_i).count{|i| Prime.prime_division(i).size == 2}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
309017 	Feb 27, 2011 10:19:46 PM 	watashi 	26A - Almost Prime 	Ruby 	Accepted 	190 ms 	4300 KB
