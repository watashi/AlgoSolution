gets
s = 0
gets.split.map(&:to_i).each_with_index do |a, i|
	s += (a - 1) * (i + 1) + 1
end
puts s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
640076 	Aug 27, 2011 6:02:31 PM 	watashi 	103A - Testing Pants for Sadness 	Ruby 	Accepted 	90 ms 	3500 KB
