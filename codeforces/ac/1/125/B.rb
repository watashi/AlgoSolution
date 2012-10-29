s = []
t = 0
gets.scan(/<.*?>/) do
	t -= 2 if $&['/']
	s << ' ' * t + $&
	t += 2 unless $&['/']
end
puts s * "\n"

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
863281 	Nov 14, 2011 4:38:26 PM 	watashi 	125B - Simple XML 	Ruby 	Accepted 	90 ms 	3700 KB 
