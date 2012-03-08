require 'prime'
x, y = gets.split.map(&:to_i)
puts Prime.find{|_| _ > x} == y ? :YES : :NO
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
402003 	Apr 19, 2011 10:51:25 PM 	watashi 	80A - Panoramixs Prediction 	Ruby 	Accepted 	110 ms 	3800 KB
